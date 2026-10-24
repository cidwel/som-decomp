; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BDE8
boss_lz_controls_dbbde8:
    ; backreference count 3, distance 348
    .byte $81, $5B
    ; literal count 32; subsequent asset bytes excluded
    .byte $1F
