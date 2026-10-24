; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CDB8
boss_lz_controls_dacdb8:
    ; backreference count 4, distance 15
    .byte $88, $0E
    ; literal count 43; subsequent asset bytes excluded
    .byte $2A
