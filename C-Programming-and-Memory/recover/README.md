# Recover (Forensic Data Recovery)

This project is a forensic program that recovers deleted JPEGs from a forensic image of a memory card. It demonstrates low-level file manipulation and understanding of digital data structures.

## Technical Highlights

- **Binary File Processing:** Scans a raw memory card image (`.raw`) to identify JPEG signatures.
- **JPEG Signature Detection:** Utilizes bitwise operations to detect specific header patterns (`0xff 0xd8 0xff`).
- **Memory Efficiency:** Processes data in 512-byte blocks to simulate physical disk sectors, ensuring efficient memory usage.
- **Dynamic File Creation:** Automatically generates and writes individual image files as they are discovered in the stream.

## Concepts Demonstrated
- File I/O in C (`fopen`, `fread`, `fwrite`, `fclose`)
- Bitwise operators and hexadecimals
- Pointer management for file streams
