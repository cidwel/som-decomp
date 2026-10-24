; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AE56
boss_lz_controls_dbae56:
    ; backreference count 3, distance 24
    .byte $80, $17
    ; literal count 18; subsequent asset bytes excluded
    .byte $11
