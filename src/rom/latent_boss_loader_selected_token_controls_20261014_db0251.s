; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0251
boss_lz_controls_db0251:
    ; backreference count 3, distance 457
    .byte $81, $C8
    ; backreference count 3, distance 413
    .byte $81, $9C
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
