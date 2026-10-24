; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D640
boss_lz_controls_dad640:
    ; backreference count 3, distance 1068
    .byte $84, $2B
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
