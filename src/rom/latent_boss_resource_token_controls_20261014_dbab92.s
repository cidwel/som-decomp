; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AB92
boss_lz_controls_dbab92:
    ; backreference count 3, distance 529
    .byte $82, $10
    ; literal count 128; subsequent asset bytes excluded
    .byte $7F
