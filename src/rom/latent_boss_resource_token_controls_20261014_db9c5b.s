; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9C5B
boss_lz_controls_db9c5b:
    ; backreference count 4, distance 8
    .byte $88, $07
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
