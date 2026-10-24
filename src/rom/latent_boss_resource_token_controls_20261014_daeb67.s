; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EB67
boss_lz_controls_daeb67:
    ; backreference count 3, distance 456
    .byte $81, $C7
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
