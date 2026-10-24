; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AE3E
boss_lz_controls_dbae3e:
    ; backreference count 3, distance 24
    .byte $80, $17
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
