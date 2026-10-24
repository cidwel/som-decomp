; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F38E
boss_lz_controls_daf38e:
    ; backreference count 3, distance 40
    .byte $80, $27
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
