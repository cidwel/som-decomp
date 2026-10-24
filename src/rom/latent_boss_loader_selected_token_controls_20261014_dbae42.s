; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AE42
boss_lz_controls_dbae42:
    ; backreference count 3, distance 24
    .byte $80, $17
    ; literal count 17; subsequent asset bytes excluded
    .byte $10
