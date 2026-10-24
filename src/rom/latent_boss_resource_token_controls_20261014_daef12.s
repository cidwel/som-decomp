; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EF12
boss_lz_controls_daef12:
    ; backreference count 4, distance 1986
    .byte $97, $C1
    ; backreference count 4, distance 580
    .byte $92, $43
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
