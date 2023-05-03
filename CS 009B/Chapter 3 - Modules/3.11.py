from datetime import date, timedelta, time

# 1 Complete read_date()

def read_date():
# 2. Use read_date() to read four (unique) date objects, putting the date objects in a list
    dates = []
    for index in range(4):
        mdate = date.fromisoformat(input())
        dates.append(mdate)
# 3. Use sorted() to sort the dates, earliest first
    dates.sort()
# 4. Output the sorted_dates in order, earliest first, in the format mm/dd/yy
    for mdate in dates:
        print(mdate.strftime("%m/%d/%Y"))
# 5. Output the number of days between the last two dates in the sorted list
#    as a positive number
    difftime = dates[3] - dates[2]
    print(difftime.days)
# 6. Output the date that is 3 weeks from the most recent date in the list
    date3week = dates[3] + timedelta(days = 21)
    print(date3week.strftime("%B %d, %Y"))
# 7. Output the full name of the day of the week of the earliest day
    print(dates[0].strftime("%A"))
    
if __name__ == '__main__':
    read_date()