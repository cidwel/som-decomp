; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F13D
boss_lz_controls_daf13d:
    ; backreference count 3, distance 1058
    .byte $84, $21
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
