; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E58E
boss_lz_controls_dae58e:
    ; backreference count 3, distance 177
    .byte $80, $B0
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
