; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E026
boss_lz_controls_dae026:
    ; backreference count 10, distance 1148
    .byte $BC, $7B
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
