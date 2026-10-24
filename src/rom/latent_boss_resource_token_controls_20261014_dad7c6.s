; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D7C6
boss_lz_controls_dad7c6:
    ; backreference count 3, distance 15
    .byte $80, $0E
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
