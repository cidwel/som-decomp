; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DEC9
boss_lz_controls_dadec9:
    ; backreference count 3, distance 15
    .byte $80, $0E
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
