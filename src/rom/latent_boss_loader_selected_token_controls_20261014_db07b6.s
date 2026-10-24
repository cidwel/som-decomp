; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $07B6
boss_lz_controls_db07b6:
    ; backreference count 10, distance 1384
    .byte $F5, $67
    ; backreference count 5, distance 1382
    .byte $A5, $65
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
