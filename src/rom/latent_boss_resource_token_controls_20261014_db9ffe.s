; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9FFE
boss_lz_controls_db9ffe:
    ; backreference count 3, distance 986
    .byte $83, $D9
    ; backreference count 3, distance 1064
    .byte $84, $27
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
