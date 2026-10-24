; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BC7F
boss_lz_controls_dbbc7f:
    ; backreference count 3, distance 15
    .byte $80, $0E
    ; literal count 24; subsequent asset bytes excluded
    .byte $17
