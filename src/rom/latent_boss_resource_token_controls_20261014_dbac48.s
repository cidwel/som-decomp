; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AC48
boss_lz_controls_dbac48:
    ; backreference count 4, distance 5
    .byte $84, $04
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
