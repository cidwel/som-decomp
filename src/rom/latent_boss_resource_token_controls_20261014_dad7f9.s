; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D7F9
boss_lz_controls_dad7f9:
    ; backreference count 3, distance 17
    .byte $80, $10
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
