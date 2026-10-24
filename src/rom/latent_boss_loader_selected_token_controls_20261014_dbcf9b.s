; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF9B
boss_lz_controls_dbcf9b:
    ; backreference count 3, distance 286
    .byte $81, $1D
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
