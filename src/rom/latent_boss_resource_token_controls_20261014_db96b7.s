; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $96B7
boss_lz_controls_db96b7:
    ; backreference count 3, distance 2144
    .byte $88, $5F
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
