; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0862
boss_lz_controls_db0862:
    ; backreference count 3, distance 1144
    .byte $84, $77
    ; backreference count 3, distance 223
    .byte $80, $DE
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
