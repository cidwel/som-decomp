; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D6FD
boss_lz_controls_dad6fd:
    ; backreference count 3, distance 501
    .byte $81, $F4
    ; literal count 17; subsequent asset bytes excluded
    .byte $10
