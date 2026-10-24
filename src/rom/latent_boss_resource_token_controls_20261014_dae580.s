; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E580
boss_lz_controls_dae580:
    ; backreference count 4, distance 1385
    .byte $8D, $68
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
