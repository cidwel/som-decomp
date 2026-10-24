; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D358
boss_lz_controls_dbd358:
    ; backreference count 4, distance 9
    .byte $84, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
