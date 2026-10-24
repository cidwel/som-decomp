; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BD03
boss_lz_controls_dbbd03:
    ; backreference count 3, distance 82
    .byte $80, $51
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
