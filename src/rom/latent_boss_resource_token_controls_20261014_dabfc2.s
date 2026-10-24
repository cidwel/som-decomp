; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BFC2
boss_lz_controls_dabfc2:
    ; backreference count 3, distance 795
    .byte $83, $1A
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
