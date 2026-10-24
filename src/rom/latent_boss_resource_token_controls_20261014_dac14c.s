; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C14C
boss_lz_controls_dac14c:
    ; backreference count 3, distance 25
    .byte $80, $18
    ; literal count 17; subsequent asset bytes excluded
    .byte $10
