; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BD13
boss_lz_controls_dbbd13:
    ; backreference count 5, distance 80
    .byte $90, $4F
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
