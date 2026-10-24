; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AAE0
boss_lz_controls_dbaae0:
    ; backreference count 4, distance 961
    .byte $87, $C0
    ; backreference count 3, distance 586
    .byte $82, $49
    ; backreference count 6, distance 957
    .byte $8F, $BC
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
