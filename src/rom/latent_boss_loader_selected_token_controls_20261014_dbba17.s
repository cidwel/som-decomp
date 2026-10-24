; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA17
boss_lz_controls_dbba17:
    ; backreference count 4, distance 139
    .byte $84, $8A
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
