; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E3BC
boss_lz_controls_dae3bc:
    ; backreference count 4, distance 689
    .byte $8A, $B0
    ; backreference count 4, distance 934
    .byte $8B, $A5
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
