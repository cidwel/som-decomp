; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C504
boss_lz_controls_dac504:
    ; backreference count 5, distance 15
    .byte $90, $0E
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
