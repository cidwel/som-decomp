; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AE7D
boss_lz_controls_dbae7d:
    ; backreference count 3, distance 38
    .byte $80, $25
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
