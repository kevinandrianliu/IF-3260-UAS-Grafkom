from xml.dom import minidom

doc = minidom.parse("peta_itb_pohon_jalan_temp.svg")  # parseString also exists
path_strings = [path.getAttribute('d') for path
                in doc.getElementsByTagName('path')]
doc.unlink()
#sr = path_strings[1].split('l')
file = open("map.txt","w")

for string in path_strings:
    file.write('9999 9999\n')
    sr = string.replace('m', '')
    sr = sr.replace('z','')
    sr = sr.split('l')
    print(sr)
    x=0
    y=0
    for string1 in sr:
        sr1 = string1.split(',')
        if (len(sr1)==2):
            print(sr1)
            x = x + int(float(sr1[0]))
            y = y + int(float(sr1[1]))
            print(x,' ',y)
            string2 = str(x)+' '+ str(y) +'\n'
            file.write(string2)
file.close()