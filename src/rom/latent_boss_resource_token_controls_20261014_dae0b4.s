; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E0B4
boss_lz_controls_dae0b4:
    ; backreference count 3, distance 1312
    .byte $85, $1F
    ; literal count 24; subsequent asset bytes excluded
    .byte $17
