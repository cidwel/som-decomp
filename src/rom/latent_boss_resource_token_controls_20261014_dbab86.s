; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AB86
boss_lz_controls_dbab86:
    ; backreference count 3, distance 176
    .byte $80, $AF
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
