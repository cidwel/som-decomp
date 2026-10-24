; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DAFF
boss_lz_controls_dadaff:
    ; backreference count 4, distance 157
    .byte $88, $9C
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
