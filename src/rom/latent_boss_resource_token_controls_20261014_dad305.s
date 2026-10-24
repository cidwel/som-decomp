; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D305
boss_lz_controls_dad305:
    ; backreference count 3, distance 110
    .byte $80, $6D
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
