; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $930E
boss_lz_controls_db930e:
    ; backreference count 7, distance 37
    .byte $C0, $24
    ; literal count 19; subsequent asset bytes excluded
    .byte $12
