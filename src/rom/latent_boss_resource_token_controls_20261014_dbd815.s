; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D815
boss_lz_controls_dbd815:
    ; backreference count 4, distance 233
    .byte $84, $E8
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
