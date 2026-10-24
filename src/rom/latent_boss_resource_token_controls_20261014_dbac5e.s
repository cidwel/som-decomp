; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AC5E
boss_lz_controls_dbac5e:
    ; backreference count 3, distance 615
    .byte $82, $66
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
