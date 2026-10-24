; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EB3B
boss_lz_controls_daeb3b:
    ; backreference count 5, distance 118
    .byte $A0, $75
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
