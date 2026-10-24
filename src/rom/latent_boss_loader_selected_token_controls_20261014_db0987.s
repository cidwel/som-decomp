; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0987
boss_lz_controls_db0987:
    ; backreference count 3, distance 1124
    .byte $84, $63
    ; backreference count 5, distance 2666
    .byte $AA, $69
    ; backreference count 4, distance 574
    .byte $92, $3D
    ; backreference count 4, distance 2195
    .byte $98, $92
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
