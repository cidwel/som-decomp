; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $064F
boss_lz_controls_db064f:
    ; backreference count 4, distance 796
    .byte $93, $1B
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
