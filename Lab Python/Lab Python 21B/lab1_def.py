from tkinter import *
from tkinter import ttk

from lab1_def_sp import add_six_base


def calc():
    summ.set(add_six_base(num1.get(), num2.get()))


root = Tk()
root.title("Calculator")


mainframe = ttk.Frame(root, padding=5)


lbl_num1 = ttk.Label(mainframe, text='num 1')


lbl_num2 = ttk.Label(mainframe, text='num 2')


lbl_sum = ttk.Label(mainframe, text='sum')


num1 = StringVar()
edt_num1 = ttk.Entry(mainframe, textvariable=num1, width=20)


num2 = StringVar()
edt_num2 = ttk.Entry(mainframe, textvariable=num2, width=20)


summ = StringVar()
edt_sum = ttk.Entry(mainframe, textvariable=summ, width=20, state="readonly")


btn_equal = ttk.Button(mainframe, text='=', command=calc)


mainframe.grid(column=0, row=0)

edt_num1.grid(column=0, row=0)
edt_num2.grid(column=0, row=1)
edt_sum.grid(column=0, row=2)

lbl_num1.grid(column=1, row=0)
lbl_num2.grid(column=1, row=1)
lbl_sum.grid(column=1, row=2)

btn_equal.grid(column=0, row=3)

root.mainloop()