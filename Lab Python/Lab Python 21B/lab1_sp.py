from tkinter import *
import tkinter.messagebox as box


def clearselection():
    choice.set(0)

def clearall():
    NumInEntry.delete(0, END)
    NumOutEntry.delete(0, END)
    choice.set(0)

def clearinput():
    NumInEntry.delete(0, END)

def clearoutput():
    NumOutEntry.delete(0, END)

def delete():
    n = NumInEntry.get()
    NumInEntry.delete(0, END)
    NumInEntry.insert(n, n[:-1])

def showinfoAu():
    box.showinfo('Info', 'Программа сделана Нгуен Ань Зунг')

def showinfoProg():
    box.showinfo('Info', 'Перевод заданного числа из 10-й сс в 6-ю и обратно')

def button_add(num):
    NumInEntry.insert(END, num)

def button_AC():
    NumInEntry.delete(0, END)

def calculate():
    if choice.get() == 0:
        box.showinfo('Error', 'Не выбрал перевод.')
    else:
        if NumInEntry.get() == '':
            box.showinfo('Error', 'Вводите число.')
            return
        instr = [i for i in NumInEntry.get()]
        if ('-' in instr and (instr[0] != '-' or (instr[0] == '-' and len(instr) == 1)) or (
                instr[0] == '-' and instr[1] == '.')) or instr[0] == '.' or instr[-1] == '.' or instr.count(
                '-') > 1 or instr.count('.') > 1:
            box.showinfo('Error', 'Вводите число снова')
            return
        t = ''
        if choice.get() == 1:
            if '.' in NumInEntry.get():
                sb = [[], '']
                neg = 0
                remainder = [i for i in NumInEntry.get().split('.')]
                remainder[0] = int(remainder[0])
                if remainder[0] < 0:
                    remainder[0] = -remainder[0]
                    neg = 1
                while remainder[0] >= 6:
                    sb[0].append(str(remainder[0] % 6))
                    remainder[0] //= 6
                sb[0].append(str(remainder[0]))
                sb[0].reverse()
                for x in sb[0]:
                    t = t + x
                sb[0] = t
                remainder[1] = float('0.' + str(remainder[1]))
                for i in range(10):
                    k = int(remainder[1] * 6)
                    remainder[1] = remainder[1] * 6 - k
                    sb[1] = sb[1] + str(k)
                t = '.'.join(sb)
                if neg:
                    t = '-' + t
            else:
                sb = []
                neg = 0
                remainder = int(NumInEntry.get())
                if remainder < 0:
                    remainder = -remainder
                    neg = 1
                while remainder >= 6:
                    sb.append(str(remainder % 6))
                    remainder //= 6
                sb.append(str(remainder))
                sb.reverse()
                for x in sb:
                    t = t + x
                if neg:
                    t = '-' + t
        else:
            if '.' in NumInEntry.get():
                s = [i for i in NumInEntry.get().split('.')]
                ans = 0
                neg = 0
                if int(s[0]) < 0:
                    s[0] = str(-int(s[0]))
                    neg = 1
                p = 1
                for x in range(len(s[0])):
                    ans += int(s[0][len(s[0]) - 1 - x]) * p
                    p *= 6
                    if int(s[0][x]) >= 6:
                        box.showinfo('Error', 'Вводите число снова')
                        return
                for i in range(len(s[1])):
                    ans += int(s[1][i]) * 6 ** (-(i + 1))
                    if int(s[1][i]) >= 6:
                        box.showinfo('Error', 'Вводите число снова')
                        return
                t = str(ans)
                if neg:
                    t = '-' + str(ans)
            else:
                s = NumInEntry.get()
                ans = 0
                neg = 0
                if int(s) < 0:
                    s = str(-int(s))
                    neg = 1
                p = 1
                for x in range(len(s)):
                    ans += int(s[len(s) - 1 - x]) * p
                    p *= 6
                    if int(s[x]) >= 6:
                        box.showinfo('Error', 'Вводите число снова')
                        return
                t = str(ans)
                if neg:
                    t = '-' + str(ans)
        NumOutEntry.delete(0, END)
        NumOutEntry.insert(0, t)

window = Tk()

#Input
NumInLabel = Label(window, text='Ввод')
NumInEntry = Entry(window, width=50)
NumInLabel.place(x=50, y=0)
NumInEntry.place(x=100, y=0)

#Choice
choice = IntVar()

#ClearButton
ButtonClearIn = Button(window, text='clear', command=clearinput)
ButtonDel = Button(window, text='Del', command=delete)
ButtonClearOut = Button(window, text='Clear', command=clearoutput)
ButtonClearIn.place(x=430, y=30)
ButtonDel.place(x=500, y=30)
ButtonClearOut.place(x=400, y=250, width=64)
ButtonClearSelection = Button(window, text='Clear Selection', command=clearselection)
ButtonClearSelection.place(x=240, y=100)

#Output
NumOutLabel = Label(window, text='Result')
NumOutEntry = Entry(window, width=40)
NumOutLabel.place(x=50, y=150)
NumOutEntry.place(x=150, y=150)

#NumberButton
Button1 = Button(window, text='1', command=lambda: button_add('1'))
Button2 = Button(window, text='2', command=lambda: button_add('2'))
Button3 = Button(window, text='3', command=lambda: button_add('3'))
Button4 = Button(window, text='4', command=lambda: button_add('4'))
Button5 = Button(window, text='5', command=lambda: button_add('5'))
Button6 = Button(window, text='6', command=lambda: button_add('6'))
Button7 = Button(window, text='7', command=lambda: button_add('7'))
Button8 = Button(window, text='8', command=lambda: button_add('8'))
Button9 = Button(window, text='9', command=lambda: button_add('9'))
Button0 = Button(window, text='0', command=lambda: button_add('0'))

Button1.place(x=100, y=200, width=50)
Button2.place(x=200, y=200, width=50)
Button3.place(x=300, y=200, width=50)
Button4.place(x=100, y=250, width=50)
Button5.place(x=200, y=250, width=50)
Button6.place(x=300, y=250, width=50)
Button7.place(x=100, y=300, width=50)
Button8.place(x=200, y=300, width=50)
Button9.place(x=300, y=300, width=50)
Button0.place(x=200, y=350, width=50)

#FunctionButton
ButtonDot = Button(window, text='.', command=lambda: button_add('.'))
ButtonMinus = Button(window, text='-', command=lambda: button_add('-'))
ButtonAC = Button(window, text='AC', command=button_AC)
ButtonEqual = Button(window, text='=', command=calculate)
ButtonCalc = Button(window, text='Calc', command=calculate)


ButtonDot.place(x=300, y=350, width=50)
ButtonMinus.place(x=100, y=350, width=50)
ButtonAC.place(x=400, y=300, width=64)
ButtonEqual.place(x=400, y=350, width=64)
ButtonCalc.place(x=400, y=200, width=64)