# Программа сделана Нгуен Ань Зунг - ИУ7И-21Б

from lab1_sp import *

window.title("Калькулятор систем счисления")
window.geometry("650x450")

#Choice
select1 = Radiobutton(window, text='Перевод из 10-й сс в 6-ю', variable=choice, value=1)
select2 = Radiobutton(window, text='Перевод из 6-й сс в 10-ю', variable=choice, value=2)
select1.place(x=50, y=70)
select2.place(x=350, y=70)

#Menu
menubar = Menu(window)

file = Menu(menubar, tearoff=0)
file.add_command(label='Exit', command=window.destroy)
menubar.add_cascade(label='File', menu=file)

edit = Menu(menubar, tearoff=0)
edit.add_command(label='Clear Input', command=clearinput)
edit.add_command(label='Clear Output', command=clearoutput)
edit.add_command(label='Clear Selection', command=clearselection)
edit.add_command(label='Clear All', command=clearall)
menubar.add_cascade(label='Edit', menu=edit)

info = Menu(menubar, tearoff=0)
info.add_command(label='About the author', command=showinfoAu)
info.add_command(label='About the program', command=showinfoProg)
menubar.add_cascade(label='Info', menu=info)

window.config(menu=menubar)
window.mainloop()