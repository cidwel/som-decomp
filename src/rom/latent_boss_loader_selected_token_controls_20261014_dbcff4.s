; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CFF4
boss_lz_controls_dbcff4:
    ; backreference count 3, distance 264
    .byte $81, $07
    ; literal count 63; subsequent asset bytes excluded
    .byte $3E
