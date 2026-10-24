; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $090C
boss_lz_controls_db090c:
    ; backreference count 6, distance 2756
    .byte $BA, $C3
    ; backreference count 3, distance 1390
    .byte $85, $6D
    ; backreference count 6, distance 2757
    .byte $BA, $C4
    ; backreference count 5, distance 2946
    .byte $AB, $81
    ; backreference count 3, distance 12
    .byte $80, $0B
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
