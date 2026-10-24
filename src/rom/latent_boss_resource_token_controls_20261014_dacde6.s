; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CDE6
boss_lz_controls_dacde6:
    ; backreference count 3, distance 480
    .byte $81, $DF
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
