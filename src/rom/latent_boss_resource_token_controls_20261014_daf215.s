; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F215
boss_lz_controls_daf215:
    ; backreference count 7, distance 139
    .byte $C0, $8A
    ; backreference count 4, distance 616
    .byte $92, $67
    ; literal count 21; subsequent asset bytes excluded
    .byte $14
