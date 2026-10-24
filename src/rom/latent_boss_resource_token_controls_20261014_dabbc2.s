; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BBC2
boss_lz_controls_dabbc2:
    ; backreference count 4, distance 128
    .byte $84, $7F
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
