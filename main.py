import ctypes
from ctypes import c_char_p, c_int, c_long, create_string_buffer
import os
import tkinter as tk
from tkinter import ttk, messagebox

class KsnetPayment:
    def __init__(self, master):
        self.master = master
        master.title("KSNET Payment")
        
        # 기본 설정값
        self.kscat_ip = tk.StringVar(value="127.0.0.1")
        self.kscat_port = tk.StringVar(value="27015")
        self.cat_id = tk.StringVar(value="DPT0TEST03")
        
        # GUI 구성
        self.setup_gui()
        
        # DLL 로드
        self.load_dll()
        
    def load_dll(self):
        """KSNET DLL 로드"""
        try:
            dll_path = os.path.join(os.path.dirname(__file__), 'Ksnetcomm.dll')
            print(f"DLL 경로: {dll_path}")
            print(f"DLL 파일 존재 여부: {os.path.exists(dll_path)}")
            
            self.ksnet_dll = ctypes.WinDLL(dll_path)
            print("DLL 로드 성공")
            
            # KSCATApproval 함수 설정
            self.kscat_approval = self.ksnet_dll.KSCATApproval
            self.kscat_approval.argtypes = [c_char_p, c_char_p, c_int, c_char_p, c_int, c_int]
            self.kscat_approval.restype = c_long
            print("함수 설정 완료")
            
        except Exception as e:
            messagebox.showerror("에러", f"DLL 로드 실패: {str(e)}")
    
    def setup_gui(self):
        """GUI 구성요소 설정"""
        # 서버 정보 프레임
        server_frame = ttk.LabelFrame(self.master, text="서버 정보", padding=10)
        server_frame.pack(fill="x", padx=5, pady=5)
        
        ttk.Label(server_frame, text="KSCAT IP:").grid(row=0, column=0, sticky="w")
        ttk.Entry(server_frame, textvariable=self.kscat_ip, state='readonly').grid(row=0, column=1, padx=5)
        
        ttk.Label(server_frame, text="KSCAT PORT:").grid(row=0, column=2, sticky="w")
        ttk.Entry(server_frame, textvariable=self.kscat_port).grid(row=0, column=3, padx=5)
        
        ttk.Label(server_frame, text="단말기번호:").grid(row=1, column=0, sticky="w")
        ttk.Entry(server_frame, textvariable=self.cat_id).grid(row=1, column=1, padx=5)
        
        # 버튼 프레임
        button_frame = ttk.Frame(self.master)
        button_frame.pack(fill="x", padx=5, pady=5)
        
        ttk.Button(button_frame, text="신용카드 승인", command=self.credit_approval).pack(fill="x", pady=2)
        ttk.Button(button_frame, text="현금영수증 승인", command=self.cash_approval).pack(fill="x", pady=2)
        ttk.Button(button_frame, text="신용카드 취소", command=self.credit_cancel).pack(fill="x", pady=2)
        ttk.Button(button_frame, text="현금영수증 취소", command=self.cash_cancel).pack(fill="x", pady=2)
        ttk.Button(button_frame, text="VANTR 취소", command=self.vantr_cancel).pack(fill="x", pady=2)
        
        # 응답 정보 프레임
        response_frame = ttk.LabelFrame(self.master, text="응답 정보", padding=10)
        response_frame.pack(fill="x", padx=5, pady=5)
        
        self.auth_date = tk.StringVar()
        self.auth_num = tk.StringVar()
        self.van_tr = tk.StringVar()
        
        ttk.Label(response_frame, text="승인 날짜:").grid(row=0, column=0, sticky="w")
        ttk.Entry(response_frame, textvariable=self.auth_date).grid(row=0, column=1, padx=5)
        
        ttk.Label(response_frame, text="승인 번호:").grid(row=1, column=0, sticky="w")
        ttk.Entry(response_frame, textvariable=self.auth_num).grid(row=1, column=1, padx=5)
        
        ttk.Label(response_frame, text="거래고유번호:").grid(row=2, column=0, sticky="w")
        ttk.Entry(response_frame, textvariable=self.van_tr).grid(row=2, column=1, padx=5)
        
        # 전문 표시 영역
        ttk.Label(self.master, text="요청전문").pack(anchor="w", padx=5)
        self.request_text = tk.Text(self.master, height=4)
        self.request_text.pack(fill="x", padx=5)
        
        ttk.Label(self.master, text="응답전문").pack(anchor="w", padx=5)
        self.response_text = tk.Text(self.master, height=4)
        self.response_text.pack(fill="x", padx=5)

    def create_request(self, tran_type, msg_code="0200", amount="000000001004"):
        """요청 전문 생성"""
        STX = chr(2)
        ETX = chr(3)
        CR = chr(13)
        FS = chr(28)
        
        request_msg = (
            f"{STX}"
            f"{tran_type}"  # 거래구분 (IC:신용카드, HK:현금영수증)
            f"01"           # 업무구분
            f"{msg_code}"   # 전문구분 (0200:승인, 0420:취소)
            f"N"            # 거래형태
            f"{self.cat_id.get()}"  # 단말기번호
            f"    "         # 업체정보
            f"000000000000" # 전문일련번호
            f" "            # POS Entry Mode
            f"{'KSVTR' if tran_type == 'MS' else '                    '}" # 거래고유번호
            f"                    " # 암호화하지않은 카드번호
            f" "            # 암호화여부
            f"################"    # SW모델번호
            f"################"    # CAT/Reader 모델번호
            f"                                        " # 암호화정보
            f"                                     "    # 카드번호
            f"{FS}"
            f"00"           # 할부개월수/거래자구분
            f"{amount}"     # 총금액
            f"000000000000" # 봉사료
            f"000000000000" # 세금
            f"000000000000" # 공급금액
            f"000000000000" # 면세금액
            f"  "           # WorkingKey Index
            f"                " # 비밀번호
            f"{self.auth_num.get() if msg_code == '0420' else '            '}" # 원거래승인번호
            f"{self.auth_date.get() if msg_code == '0420' else '      '}"     # 원거래승인일자
            f"{' ' * 163}"  # 사용자정보~DCC
            f"X"            # 전자서명유무
            f"{ETX}"
            f"{CR}"
        )
        
        # 전문길이 추가
        msg_len = f"{len(request_msg):04d}"
        request_msg = msg_len + request_msg
        
        return request_msg

    def process_transaction(self, request_msg):
        """거래 처리 및 응답 처리"""
        try:
            # 요청 전문 표시
            self.request_text.delete(1.0, tk.END)
            self.request_text.insert(tk.END, request_msg)
            
            # 응답 버퍼 준비
            response_buffer = create_string_buffer(4096)
            
            # KSCATApproval 호출
            result = self.kscat_approval(
                response_buffer,
                self.kscat_ip.get().encode('utf-8'),
                int(self.kscat_port.get()),
                request_msg.encode('euc-kr'),
                len(request_msg),
                0
            )
            
            # 응답 처리
            response = response_buffer.value.decode('euc-kr')
            self.response_text.delete(1.0, tk.END)
            self.response_text.insert(tk.END, response)
            
            if result <= 0:
                messagebox.showerror("실패", f"요청 실패: {result}\n{response}")
            else:
                messagebox.showinfo("성공", f"요청 성공: {result}\n{response}")
                
                # 승인정보 파싱
                self.auth_date.set(response[49:55])
                self.auth_num.set(response[94:106])
                self.van_tr.set(response[106:126])
                
        except Exception as e:
            messagebox.showerror("에러", str(e))

    def credit_approval(self):
        """신용카드 승인"""
        request_msg = self.create_request("IC")
        self.process_transaction(request_msg)
        
    def cash_approval(self):
        """현금영수증 승인"""
        request_msg = self.create_request("HK", amount="000000000700")
        self.process_transaction(request_msg)
        
    def credit_cancel(self):
        """신용카드 취소"""
        request_msg = self.create_request("IC", "0420")
        self.process_transaction(request_msg)
        
    def cash_cancel(self):
        """현금영수증 취소"""
        request_msg = self.create_request("HK", "0420", "000000000700")
        self.process_transaction(request_msg)
        
    def vantr_cancel(self):
        """VANTR 취소"""
        request_msg = self.create_request("MS", "0420")
        self.process_transaction(request_msg)

def main():
    root = tk.Tk()
    app = KsnetPayment(root)
    root.mainloop()

if __name__ == "__main__":
    main()