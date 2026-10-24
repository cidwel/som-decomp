; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C21E
boss_lz_controls_dac21e:
    ; backreference count 3, distance 110
    .byte $80, $6D
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
