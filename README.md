# TUGAS KECIL 1 IF2211 STRATEGI ALGORITMA
## Penyelesaian Word Search Puzzle dengan Algoritma Brute Force

Program ini merupakan program yang dapat menyelesaikan permainan Word Search Puzzle secara brute force. Program ditulis dengan menggunakan bahasa pemrograman C dan telah di-compile menggunakan compiler gcc.

## Requirements
Program hanya menerima masukan berupa file dengan format .txt yang terdiri dari puzzle dan diikuti dengan sebuah baris kosong serta daftar kata-kata yang harus dicari, masing-masing dipisahkan oleh sebuah baris baru.

Berikut adalah contoh isi file yang valid.

    J S O L U T I S 
    S U N A R U U A 
    N E P T U N E T 
    S O N I E I S U 
    R C E V T R E R 
    A H T R A E S N 
    M M E R C U R Y 

    EARTH 
    JUPITER 
    MARS 
    MERCURY 
    NEPTUNE 
    SATURN 
    URANUS 
    VENUS

Ukuran maksimal dari puzzle yang dapat diterima adalah 50x50 dan panjang maksimal kata yang akan dicari ialah sebanyak 20 huruf.

## Cara Menjalankan Program

Pastikan terlebih dahulu bahwa Anda berada dalam folder utama, lalu ketikkan instruksi di bawah ini pada command line untuk menjalankan executable file yang berada pada subfolder `bin`.
```
./bin/main
```
Program akan meminta input nama file. File puzzle yang akan diselesaikan harus berada pada subfolder `test`. Ketikkan nama file diikuti dengan '.txt'. Sebagai contoh :

```
Enter file name : large3.txt
```

Ketik enter, maka program akan menyelesaikan puzzle pada file.

---

Disusun oleh Christine Hutabarat (13520005) - 13520005@std.stei.itb.ac.id