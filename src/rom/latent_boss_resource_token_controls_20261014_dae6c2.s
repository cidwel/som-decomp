; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E6C2
boss_lz_controls_dae6c2:
    ; backreference count 3, distance 35
    .byte $80, $22
    ; literal count 33; subsequent asset bytes excluded
    .byte $20
