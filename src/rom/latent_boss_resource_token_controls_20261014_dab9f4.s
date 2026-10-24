; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B9F4
boss_lz_controls_dab9f4:
    ; backreference count 3, distance 75
    .byte $80, $4A
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
