import pandas as pd
import os

input_dir = "input"  # Folder where .xlsx files are stored
output_dir = "csv_input"  # Folder where .csv files will be saved

os.makedirs(output_dir, exist_ok=True)

# Convert all .xlsx files to .csv
for filename in os.listdir(input_dir):
    if filename.endswith(".xlsx"):
        xlsx_path = os.path.join(input_dir, filename)
        csv_path = os.path.join(output_dir, filename.replace(".xlsx", ".csv"))
        
        df = pd.read_excel(xlsx_path)
        df.to_csv(csv_path, index=False)
        
        print(f"Converted {filename} to {csv_path}")

print("Conversion completed.")
