; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E310
boss_lz_controls_dae310:
    ; backreference count 3, distance 176
    .byte $80, $AF
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
