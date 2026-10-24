; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C820
boss_lz_controls_dac820:
    ; backreference count 3, distance 1143
    .byte $84, $76
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
