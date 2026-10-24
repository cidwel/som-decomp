; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9AC0
boss_lz_controls_db9ac0:
    ; backreference count 3, distance 1119
    .byte $84, $5E
    ; literal count 50; subsequent asset bytes excluded
    .byte $31
