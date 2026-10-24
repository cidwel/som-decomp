; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BC75
boss_lz_controls_dabc75:
    ; backreference count 6, distance 37
    .byte $8C, $24
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
