; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9155
boss_lz_controls_db9155:
    ; backreference count 3, distance 6
    .byte $80, $05
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
