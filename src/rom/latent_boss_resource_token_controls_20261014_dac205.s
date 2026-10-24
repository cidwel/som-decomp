; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C205
boss_lz_controls_dac205:
    ; backreference count 3, distance 54
    .byte $80, $35
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
