; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B287
boss_lz_controls_dbb287:
    ; backreference count 3, distance 480
    .byte $81, $DF
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
