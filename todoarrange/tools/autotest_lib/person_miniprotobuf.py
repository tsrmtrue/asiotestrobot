person = {
    "name" :[1,'string','option'],
    "name" :[2,'string','option'],
    'age'  :[3,'int','option'],
    'skill':[4,'string','repeated'],
}

student = {
    'classc':[1,'int','option'],
    'who':[2,'person','option'],
    'school':[3,'string','option'],    
}

struct = {
    'person':person,
    'student':student,
          }