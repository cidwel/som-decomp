; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BCD3
boss_lz_controls_dbbcd3:
    ; backreference count 3, distance 6
    .byte $80, $05
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
