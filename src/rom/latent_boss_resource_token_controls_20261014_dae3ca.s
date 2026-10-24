; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E3CA
boss_lz_controls_dae3ca:
    ; backreference count 4, distance 1319
    .byte $8D, $26
    ; literal count 32; subsequent asset bytes excluded
    .byte $1F
