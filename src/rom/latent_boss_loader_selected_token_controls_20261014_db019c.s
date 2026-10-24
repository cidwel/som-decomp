; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $019C
boss_lz_controls_db019c:
    ; backreference count 3, distance 7
    .byte $80, $06
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
