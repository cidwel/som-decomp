; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BC92
boss_lz_controls_dabc92:
    ; backreference count 10, distance 80
    .byte $9C, $4F
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
