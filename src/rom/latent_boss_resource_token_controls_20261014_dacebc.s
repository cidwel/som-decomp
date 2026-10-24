; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CEBC
boss_lz_controls_dacebc:
    ; backreference count 3, distance 822
    .byte $83, $35
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
