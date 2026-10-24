; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $077F
boss_lz_controls_db077f:
    ; backreference count 6, distance 2688
    .byte $BA, $7F
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
