; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E35F
boss_lz_controls_dae35f:
    ; backreference count 6, distance 66
    .byte $98, $41
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
