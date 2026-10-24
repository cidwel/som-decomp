; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $98CB
boss_lz_controls_db98cb:
    ; backreference count 3, distance 1085
    .byte $84, $3C
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
