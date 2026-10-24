; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D680
boss_lz_controls_dad680:
    ; backreference count 5, distance 550
    .byte $92, $25
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
