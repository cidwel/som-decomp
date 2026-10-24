; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AE6B
boss_lz_controls_dbae6b:
    ; backreference count 3, distance 134
    .byte $80, $85
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
