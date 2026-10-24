; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E7C1
boss_lz_controls_dae7c1:
    ; backreference count 3, distance 32
    .byte $80, $1F
    ; literal count 20; subsequent asset bytes excluded
    .byte $13
