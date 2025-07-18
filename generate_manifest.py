import os
import hashlib
import json
from pathlib import Path

def compute_sha256(file_path):
    h = hashlib.sha256()
    with open(file_path, "rb") as f:
        for chunk in iter(lambda: f.read(8192), b""):
            h.update(chunk)
    return h.hexdigest()

def generate_manifest(root_dir, version):
    manifest = {
        "version": version,
        "files": []
    }
    root = Path(root_dir)
    
    # Dosya/klasörler eklenecek veya atlanacakları belirt
    SKIP_EXTS = {".cpp", ".h", ".py", ".md", ".json"}
    SKIP_NAMES = {".gitignore", "LICENSE", "license.txt", "README.md"}
    
    for file_path in root.rglob("*"):
        if not file_path.is_file():
            continue

        # .git klasörü altındakileri atla
        if ".git" in file_path.parts:
            continue

        # Belirli uzantıları atla
        if file_path.suffix.lower() in SKIP_EXTS:
            continue

        # Belirli dosya isimlerini atla
        if file_path.name in SKIP_NAMES:
            continue

        # Relatif yol ve düz dosya adı
        rel_path = str(file_path.relative_to(root)).replace("\\", "/")
        asset_name = file_path.name  # Orijinal dosya adı

        manifest["files"].append({
            "path": rel_path,
            "assetName": file_path.name,        # <–– sadece dosya adı
            "hash": compute_sha256(file_path)
        })

    return manifest

if __name__ == "__main__":
    build_directory = "C:/Users/ronit/Desktop/breadsexe"
    version = "v1.1.5"
    manifest = generate_manifest(build_directory, version)
    with open("manifest.json", "w", encoding="utf-8") as f:
        json.dump(manifest, f, ensure_ascii=False, indent=2)
    print("manifest.json oluşturuldu!")
