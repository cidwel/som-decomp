; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CBD5
boss_lz_controls_dbcbd5:
    ; backreference count 3, distance 190
    .byte $80, $BD
    ; literal count 17; subsequent asset bytes excluded
    .byte $10
