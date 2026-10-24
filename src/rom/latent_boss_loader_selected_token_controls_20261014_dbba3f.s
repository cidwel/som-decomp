; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA3F
boss_lz_controls_dbba3f:
    ; backreference count 3, distance 337
    .byte $81, $50
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
