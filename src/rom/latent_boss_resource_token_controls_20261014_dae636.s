; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E636
boss_lz_controls_dae636:
    ; backreference count 3, distance 14
    .byte $80, $0D
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
