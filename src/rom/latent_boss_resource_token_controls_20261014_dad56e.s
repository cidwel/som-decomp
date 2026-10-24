; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D56E
boss_lz_controls_dad56e:
    ; backreference count 4, distance 128
    .byte $88, $7F
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
