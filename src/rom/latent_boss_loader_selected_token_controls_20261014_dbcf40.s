; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF40
boss_lz_controls_dbcf40:
    ; backreference count 3, distance 752
    .byte $82, $EF
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
