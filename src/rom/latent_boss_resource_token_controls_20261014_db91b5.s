; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $91B5
boss_lz_controls_db91b5:
    ; backreference count 4, distance 287
    .byte $91, $1E
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
