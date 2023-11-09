x  = input("Type the filename: ")

x = x.lower()
x = x.strip()

if x.endswith(".jpg") or x.endswith(".jpeg"):
    print("image/jpeg")
elif x.endswith(".png"):
    print("image/png")
elif(x.endswith(".gif")):
    print("image/gif")
elif(x.endswith(".pdf")):
    print("application/pdf")
elif(x.endswith(".txt")):
    print("text/plain")
elif(x.endswith(".zip")):
    print("application/zip")
else:
    print("application/octet-stream")

"""
şöyle de yapılabilirmiş:

name, delim, extension = input ("File Name: ").strip().lower().rpartition(".")



# Print the media type/MIME Type
match extension:
    case "gif":
        print("image/gif")
    case "jpg":
        print("image/jpeg")
    case "jpeg":
        print("image/jpeg")
    case "png":
        print("image/png")
    case "pdf":
        print("application/pdf")
    case "txt":
        print("text/plain")
    case "zip":
        print("application/zip")
    case other:
        print("application/octet-stream")




"""