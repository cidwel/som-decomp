; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA64
boss_lz_controls_dbba64:
    ; backreference count 4, distance 230
    .byte $84, $E5
    ; literal count 43; subsequent asset bytes excluded
    .byte $2A
