; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA92
boss_lz_controls_dbba92:
    ; backreference count 4, distance 10
    .byte $84, $09
    ; literal count 42; subsequent asset bytes excluded
    .byte $29
