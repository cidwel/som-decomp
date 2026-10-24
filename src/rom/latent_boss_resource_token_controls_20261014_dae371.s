; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E371
boss_lz_controls_dae371:
    ; backreference count 3, distance 33
    .byte $80, $20
    ; literal count 23; subsequent asset bytes excluded
    .byte $16
