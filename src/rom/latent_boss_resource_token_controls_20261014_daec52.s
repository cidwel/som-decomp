; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EC52
boss_lz_controls_daec52:
    ; backreference count 3, distance 770
    .byte $83, $01
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
