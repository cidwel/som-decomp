; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CAA2
boss_lz_controls_dacaa2:
    ; backreference count 3, distance 202
    .byte $80, $C9
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
