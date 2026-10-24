; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9B24
boss_lz_controls_db9b24:
    ; backreference count 3, distance 211
    .byte $80, $D2
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
