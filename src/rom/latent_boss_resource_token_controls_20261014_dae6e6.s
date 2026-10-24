; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E6E6
boss_lz_controls_dae6e6:
    ; backreference count 4, distance 71
    .byte $90, $46
    ; literal count 128; subsequent asset bytes excluded
    .byte $7F
