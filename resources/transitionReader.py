import pandas as pd

file_path = '/home/hij555/Programming/Compiladores/Script/DFA.csv'
df = pd.read_csv(file_path)
df.head()

def format_dfa_output(df):
    result = []
    for _, row in df.iterrows():
        dfa_number = int(row['DFA'])
        dfa_data = []
        for column in df.columns[1:]:
            value = row[column]
            if pd.notna(value):
                dfa_data.append(f"{{'{column}', {int(value)}}}")
        if dfa_data:
            dfa_str = f"{{{dfa_number}, {{{', '.join(dfa_data)}}}}}"
            result.append(dfa_str)

    return ",\n".join(result)

formatted_dfa_output = format_dfa_output(df)

with open('/home/hij555/Programming/Compiladores/Script/my_file.txt', 'w') as file:
    file.write(formatted_dfa_output)

print("String has been written to the file.")
