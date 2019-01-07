
from random import randint

namelist1 = ["SMITH","JOHNSON","WILLIAMS","BROWN","JONES","MILLER","DAVIS","GARCIA","RODRIGUEZ","WILSON","MARTINEZ","ANDERSON","TAYLOR","THOMAS","HERNANDEZ","MOORE","MARTIN","JACKSON","THOMPSON","WHITE"]
namelist2 = ["LOPEZ","LEE","GONZALEZ","HARRIS","CLARK","LEWIS","ROBINSON","WALKER","PEREZ","HALL","YOUNG","ALLEN","SANCHEZ","WRIGHT","KING","SCOTT","GREEN","BAKER","ADAMS","NELSON"]
namelist3 = ["HILL","RAMIREZ","CAMPBELL","MITCHELL","ROBERTS","CARTER","PHILLIPS","EVANS","TURNER","TORRES","PARKER","COLLINS","EDWARDS","STEWART","FLORES","MORRIS","NGUYEN","MURPHY","RIVERA","COOK"]

contact = []

def gen():
    f = open("test10.txt","w+")
    for i in range(10):
        listchoice = randint(1,3)
        if listchoice == 1:
            fnamechoice = randint(0,19)
            lnamechoice = randint(0,19)
            fname = namelist1[fnamechoice]
            lname = namelist2[lnamechoice]
        elif listchoice == 2:
            fnamechoice = randint(0,19)
            lnamechoice = randint(0,19)
            fname = namelist2[fnamechoice]
            lname = namelist3[lnamechoice]
        elif listchoice == 3:
            fnamechoice = randint(0,19)
            lnamechoice = randint(0,19)
            fname = namelist3[fnamechoice]
            lname = namelist1[lnamechoice]
        zipgen = randint(10000,99999)
        writeline = (fname.strip(),lname.strip(),"*","*","*","Eugene","OR",str(zipgen))
        f.write('\t'.join(writeline)+'\n')

    f.close()

if __name__ == "__main__":
    gen()