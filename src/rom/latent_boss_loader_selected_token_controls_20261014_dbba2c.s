; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA2C
boss_lz_controls_dbba2c:
    ; backreference count 4, distance 336
    .byte $85, $4F
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F
