; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B40
boss_lz_controls_db0b40:
    ; backreference count 5, distance 1788
    .byte $A6, $FB
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
