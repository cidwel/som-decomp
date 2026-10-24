; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA96
boss_lz_controls_dbca96:
    ; backreference count 4, distance 310
    .byte $91, $35
    ; backreference count 4, distance 22
    .byte $90, $15
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
