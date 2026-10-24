; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0685
boss_lz_controls_db0685:
    ; backreference count 7, distance 9
    .byte $C0, $08
    ; backreference count 3, distance 1501
    .byte $85, $DC
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
