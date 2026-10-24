; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF55
boss_lz_controls_dadf55:
    ; backreference count 5, distance 164
    .byte $90, $A3
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
