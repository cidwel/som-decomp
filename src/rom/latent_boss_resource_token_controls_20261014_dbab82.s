; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AB82
boss_lz_controls_dbab82:
    ; backreference count 3, distance 76
    .byte $80, $4B
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
