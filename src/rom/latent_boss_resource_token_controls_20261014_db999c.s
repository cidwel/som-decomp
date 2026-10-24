; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $999C
boss_lz_controls_db999c:
    ; backreference count 3, distance 540
    .byte $82, $1B
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F
