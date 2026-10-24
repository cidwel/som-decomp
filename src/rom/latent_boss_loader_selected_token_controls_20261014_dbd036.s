; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D036
boss_lz_controls_dbd036:
    ; backreference count 3, distance 166
    .byte $80, $A5
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
