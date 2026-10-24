; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B907
boss_lz_controls_dab907:
    ; backreference count 3, distance 212
    .byte $80, $D3
    ; backreference count 3, distance 686
    .byte $82, $AD
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
