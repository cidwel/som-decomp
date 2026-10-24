; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E1F0
boss_lz_controls_dae1f0:
    ; backreference count 4, distance 34
    .byte $88, $21
    ; backreference count 12, distance 1
    .byte $C8, $00
    ; literal count 19; subsequent asset bytes excluded
    .byte $12
