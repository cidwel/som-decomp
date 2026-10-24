; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BCD7
boss_lz_controls_dabcd7:
    ; backreference count 3, distance 43
    .byte $80, $2A
    ; backreference count 3, distance 51
    .byte $80, $32
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
