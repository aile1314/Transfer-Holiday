print("年月を指定（例：2022 1）")
[year, month]=[int(i) for i in input().split()]
if month == 2:
  if year % 4 == 0 and year % 100 != 0 or year % 400 == 0:
    dm = 29
  else:
    dm = 28
elif month == 4 or month == 6 or month == 9 or month == 11:
  dm = 30
elif month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12:
  dm = 31
else:
  dm = 0
print(year,month, dm)

sequence=[1,0,5]
i=len(sequence)

day = 1
if month == 1 or month == 2:
  year -= 1
  month += 12
weekday = (year + year//4 - year//100 + year//400 +(13*month + 8)//5 + day) % 7
weekday = int(weekday)
if weekday == 0:
  print("Sunday")
elif weekday == 1:
  print("Monday")
elif weekday == 2:
  print("Tuesday")
elif weekday == 3:
  print("Wednesday")
elif weekday == 4:
  print("Thurseday")
elif weekday == 5:
  print("Friday")
elif weekday == 6:
  print("Saturday")

hd = []
sd = 0
for i in range(1, dm+1):
  d = i + weekday
  if month == 13:
    if d // 7 == 2 and d % 7 == 2 or (i >= 1 and i <= 3) or d % 7 == 0 or d % 7 == 1:
      hd.append(i)
  elif month == 14:
    if i == 11 or i == 23 or d % 7 == 0 or d % 7 == 1:
      if (i == 11 and d % 7 == 1) or (i == 23 and d % 7 == 1):
        hd.append(i)
        i += 1
      hd.append(i)
  elif month == 3:
    if sd == 0:
      print("春分の日を入力")
      sd = int(input())
    if d % 7 == 0 or d % 7 == 1 or i == sd:
      if i == sd and d % 7 == 1:
        hd.append(i)
        i += 1
      hd.append(i)
  elif month == 4:
    if d % 7 == 0 or d % 7 == 1 or i == 29:
      if i == 29 and d % 7 == 1:
        hd.append(i)
        i += 1
      hd.append(i)
  elif month == 5:
    if d % 7 == 0 or d % 7 == 1 or (i >= 3 and i <= 5):
      if (i >= 3 and i <= 5) and d % 7 == 1:
        hd.append(6)
      hd.append(i)
      hd.sort()
  elif month == 6:
    if d % 7 == 0 or d % 7 == 1:
      hd.append(i)
  elif month == 7:
    if d % 7 == 0 or d % 7 == 1 or (d // 7 == 3 and d % 7 == 2):
      hd.append(i)
  elif month == 8:
    if d % 7 == 0 or d % 7 == 1 or i == 11:
      if i == 11 and d % 7 == 1:
        hd.append(i)
        i += 1
      hd.append(i)
  elif month == 9:
    if sd == 0:
      print("秋分の日を入力")
      sd = int(input())
    if d % 7 == 0 or d % 7 == 1 or i == sd or (d // 7 == 3 and d  % 7 == 2):
      if i == sd and d % 7 == 1:
        hd.append(i)
        i += 1
      hd.append(i)
  elif month == 10:
    if d % 7 == 0 or d % 7 == 1 or (d // 7 == 2 and d % 7 == 2):
      hd.append(i)
  elif month == 11:
    if d % 7 == 0 or d % 7 == 1 or i == 3 or i == 23:
      if (i == 3 and d % 7 == 1) or (i == 23 and d % 7 == 1):
        hd.append(i)
        i += 1
      hd.append(i)
  elif month == 12:
    if d % 7 == 0 or d % 7 == 1 or (i >= 29 and i <= 31):
      hd.appemd(i)
  
print("勤務表の休みを入力")
s_hd = input().split()
for i in range(len(s_hd)):
  s_hd[i] = int(s_hd[i])
print(s_hd)

t_hd = []
t_c = []
for i in range(len(s_hd)):
  if not(s_hd[i] in hd):
    t_hd.append(s_hd[i])
print(t_hd)
for i in range(len(hd)):
  if not(hd[i] in s_hd):
    t_c.append(hd[i])
print(t_c)

print("泊まり勤務を入力")
night_shift = input().split()

print("前月に振休を前借りした？　Yes:y, No:n")
l_m = input()
if l_m == 'y':
  print("前月に前借りした振休数を入力")
  l_m = int(input())
  for i in range(l_m):
    t_hd[(len(t_hd) - 1 - i)] = '前借'

print("前月に代出した？　Yes:y, No:n")
l_m = input()
if l_m == 'y':
  print("前月の代出数を入力")
  l_m = int(input())
  print("代休取得日を入力")
  day = input().split()
  for j in range(len(day)):
    day[j] = int(day[j])
  for j in range(len(day)):
    a = 0
    for i in range(len(t_hd)):
      if t_hd[i] == day[j]:
        t_c.insert(i, "代休") 
        a = a + 1
    if a == 0:
      t_c.append('代休')

print("　振休日　　振出日")
for i in range(len(t_c)):
  print(f"{t_hd[i]:>{6}}"+ f"{t_c[i]:>{10}}")
print("泊まり勤務　明け勤務")
for i in range(len(night_shift)):
  print((f"{night_shift[i]:>{6}}"+ f"{str(int(night_shift[i]) + 1):>{11}}"))