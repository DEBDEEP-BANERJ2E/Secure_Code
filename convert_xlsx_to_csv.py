import pandas as pd
import os

input_dir = "input"  # Folder where .xlsx files are stored
output_dir = "csv_input"  # Folder where .csv files will be saved

os.makedirs(output_dir, exist_ok=True)

for filename in os.listdir(input_dir):
    if filename.endswith(".xlsx"):
        xlsx_path = os.path.join(input_dir, filename)

        # Special handling for SOD_Ruleset.xlsx
        if filename == "SOD_Ruleset.xlsx":
            sheets = ["SOD_MASTER", "ENTITLEMENT_MST"]
            for sheet in sheets:
                df = pd.read_excel(xlsx_path, sheet_name=sheet)
                csv_path = os.path.join(output_dir, f"{sheet}.csv")
                df.to_csv(csv_path, index=False)
                print(f"Converted sheet '{sheet}' to {csv_path}")
        else:
            # Convert other .xlsx files with a single sheet
            df = pd.read_excel(xlsx_path)
            csv_path = os.path.join(output_dir, filename.replace(".xlsx", ".csv"))
            df.to_csv(csv_path, index=False)
            print(f"Converted {filename} to {csv_path}")

print("Conversion completed.")
