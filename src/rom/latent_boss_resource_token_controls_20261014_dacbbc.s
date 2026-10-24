; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CBBC
boss_lz_controls_dacbbc:
    ; backreference count 3, distance 454
    .byte $81, $C5
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
