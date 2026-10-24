; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0145
boss_lz_controls_db0145:
    ; backreference count 4, distance 196
    .byte $90, $C3
    ; backreference count 3, distance 223
    .byte $80, $DE
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
