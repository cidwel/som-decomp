; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D66D
boss_lz_controls_dad66d:
    ; backreference count 3, distance 1186
    .byte $84, $A1
    ; backreference count 18, distance 314
    .byte $F9, $39
    ; backreference count 14, distance 314
    .byte $D9, $39
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
