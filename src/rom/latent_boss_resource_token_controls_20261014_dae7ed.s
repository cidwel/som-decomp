; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E7ED
boss_lz_controls_dae7ed:
    ; backreference count 4, distance 174
    .byte $90, $AD
    ; literal count 33; subsequent asset bytes excluded
    .byte $20
