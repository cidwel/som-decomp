; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C0BA
boss_lz_controls_dac0ba:
    ; backreference count 4, distance 756
    .byte $86, $F3
    ; backreference count 3, distance 943
    .byte $83, $AE
    ; backreference count 6, distance 394
    .byte $8D, $89
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
