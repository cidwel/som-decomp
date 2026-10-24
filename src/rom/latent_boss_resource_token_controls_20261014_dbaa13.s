; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AA13
boss_lz_controls_dbaa13:
    ; backreference count 4, distance 730
    .byte $86, $D9
    ; backreference count 3, distance 252
    .byte $80, $FB
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
