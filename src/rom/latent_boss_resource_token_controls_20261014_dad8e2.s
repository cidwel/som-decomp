; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D8E2
boss_lz_controls_dad8e2:
    ; backreference count 8, distance 1
    .byte $A8, $00
    ; literal count 38; subsequent asset bytes excluded
    .byte $25
