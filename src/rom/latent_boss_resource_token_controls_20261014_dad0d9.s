; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D0D9
boss_lz_controls_dad0d9:
    ; backreference count 4, distance 25
    .byte $88, $18
    ; backreference count 5, distance 1
    .byte $90, $00
    ; literal count 63; subsequent asset bytes excluded
    .byte $3E
