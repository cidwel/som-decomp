; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BC00
boss_lz_controls_dabc00:
    ; backreference count 4, distance 17
    .byte $84, $10
    ; backreference count 4, distance 992
    .byte $87, $DF
    ; backreference count 4, distance 854
    .byte $87, $55
    ; literal count 18; subsequent asset bytes excluded
    .byte $11
