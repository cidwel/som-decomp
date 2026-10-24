; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DD6A
boss_lz_controls_dadd6a:
    ; backreference count 3, distance 532
    .byte $82, $13
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
