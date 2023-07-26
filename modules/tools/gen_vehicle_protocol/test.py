def check_quotation_marks(filename):
    with open(filename, 'r') as file:
        for line_number, line in enumerate(file, start=1):
            if line.count('"') % 2 != 0 or line.count("'") % 2 != 0:
                print(f'Mismatched quotation marks on line {line_number}: {line.strip()}')

file = 'es6.dbc'
check_quotation_marks(file)
