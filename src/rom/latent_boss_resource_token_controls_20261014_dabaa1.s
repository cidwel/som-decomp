; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BAA1
boss_lz_controls_dabaa1:
    ; backreference count 9, distance 55
    .byte $98, $36
    ; backreference count 17, distance 270
    .byte $B9, $0D
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
