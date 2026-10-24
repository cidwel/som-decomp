; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BF36
boss_lz_controls_dbbf36:
    ; backreference count 6, distance 86
    .byte $98, $55
    ; literal count 86; subsequent asset bytes excluded
    .byte $55
