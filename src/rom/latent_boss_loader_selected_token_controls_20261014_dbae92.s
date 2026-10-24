; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AE92
boss_lz_controls_dbae92:
    ; backreference count 3, distance 24
    .byte $80, $17
    ; literal count 23; subsequent asset bytes excluded
    .byte $16
