; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B591
boss_lz_controls_dbb591:
    ; backreference count 7, distance 417
    .byte $91, $A0
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
