; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $082B
boss_lz_controls_db082b:
    ; backreference count 8, distance 2172
    .byte $D8, $7B
    ; backreference count 5, distance 2042
    .byte $A7, $F9
    ; backreference count 3, distance 942
    .byte $83, $AD
    ; backreference count 4, distance 56
    .byte $90, $37
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
