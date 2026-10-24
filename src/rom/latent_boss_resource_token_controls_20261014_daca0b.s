; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA0B
boss_lz_controls_daca0b:
    ; backreference count 3, distance 895
    .byte $83, $7E
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
