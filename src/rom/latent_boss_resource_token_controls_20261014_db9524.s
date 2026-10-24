; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9524
boss_lz_controls_db9524:
    ; backreference count 4, distance 11
    .byte $90, $0A
    ; backreference count 3, distance 38
    .byte $80, $25
    ; literal count 34; subsequent asset bytes excluded
    .byte $21
