; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B211
boss_lz_controls_dbb211:
    ; backreference count 4, distance 425
    .byte $85, $A8
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
