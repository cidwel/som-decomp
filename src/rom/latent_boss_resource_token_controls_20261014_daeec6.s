; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EEC6
boss_lz_controls_daeec6:
    ; backreference count 4, distance 106
    .byte $90, $69
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
