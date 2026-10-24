; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB0B
boss_lz_controls_dacb0b:
    ; backreference count 3, distance 1108
    .byte $84, $53
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
