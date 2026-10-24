; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AC1E
boss_lz_controls_dbac1e:
    ; backreference count 3, distance 652
    .byte $82, $8B
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
