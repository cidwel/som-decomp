; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AC58
boss_lz_controls_dbac58:
    ; backreference count 3, distance 15
    .byte $80, $0E
    ; backreference count 3, distance 614
    .byte $82, $65
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
