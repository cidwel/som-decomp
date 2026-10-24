; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F14E
boss_lz_controls_daf14e:
    ; backreference count 3, distance 2224
    .byte $88, $AF
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
