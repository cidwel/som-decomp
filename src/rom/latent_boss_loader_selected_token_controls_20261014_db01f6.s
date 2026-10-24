; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $01F6
boss_lz_controls_db01f6:
    ; backreference count 4, distance 8
    .byte $90, $07
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
