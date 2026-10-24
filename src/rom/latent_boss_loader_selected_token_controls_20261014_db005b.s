; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $005B
boss_lz_controls_db005b:
    ; backreference count 4, distance 27
    .byte $90, $1A
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
