; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BDE0
boss_lz_controls_dabde0:
    ; backreference count 3, distance 245
    .byte $80, $F4
    ; literal count 24; subsequent asset bytes excluded
    .byte $17
