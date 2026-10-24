; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $00CE
boss_lz_controls_db00ce:
    ; backreference count 4, distance 197
    .byte $90, $C4
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
