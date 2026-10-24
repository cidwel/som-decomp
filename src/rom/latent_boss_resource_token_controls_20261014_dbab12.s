; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AB12
boss_lz_controls_dbab12:
    ; backreference count 3, distance 451
    .byte $81, $C2
    ; literal count 36; subsequent asset bytes excluded
    .byte $23
