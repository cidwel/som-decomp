; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0419
boss_lz_controls_db0419:
    ; backreference count 3, distance 85
    .byte $80, $54
    ; backreference count 7, distance 1337
    .byte $C5, $38
    ; backreference count 3, distance 1155
    .byte $84, $82
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
