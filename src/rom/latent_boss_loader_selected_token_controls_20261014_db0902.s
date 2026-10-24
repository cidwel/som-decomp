; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0902
boss_lz_controls_db0902:
    ; backreference count 5, distance 175
    .byte $A0, $AE
    ; backreference count 6, distance 1384
    .byte $B5, $67
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
