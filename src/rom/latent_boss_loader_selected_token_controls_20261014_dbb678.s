; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B678
boss_lz_controls_dbb678:
    ; backreference count 4, distance 59
    .byte $84, $3A
    ; backreference count 3, distance 236
    .byte $80, $EB
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
