; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E254
boss_lz_controls_dae254:
    ; backreference count 3, distance 895
    .byte $83, $7E
    ; backreference count 4, distance 102
    .byte $88, $65
    ; literal count 17; subsequent asset bytes excluded
    .byte $10
