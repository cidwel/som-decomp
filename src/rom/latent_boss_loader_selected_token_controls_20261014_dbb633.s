; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B633
boss_lz_controls_dbb633:
    ; backreference count 3, distance 807
    .byte $83, $26
    ; backreference count 3, distance 31
    .byte $80, $1E
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
