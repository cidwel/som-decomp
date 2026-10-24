; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A7A9
boss_lz_controls_dba7a9:
    ; backreference count 4, distance 204
    .byte $84, $CB
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
