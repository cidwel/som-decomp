; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0D7E
boss_lz_controls_db0d7e:
    ; backreference count 3, distance 504
    .byte $81, $F7
    ; literal count 110; subsequent asset bytes excluded
    .byte $6D
