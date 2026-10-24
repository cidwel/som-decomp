; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C7B9
boss_lz_controls_dac7b9:
    ; backreference count 10, distance 566
    .byte $BA, $35
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
