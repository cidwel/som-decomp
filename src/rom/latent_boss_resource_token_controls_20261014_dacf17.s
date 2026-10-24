; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF17
boss_lz_controls_dacf17:
    ; backreference count 3, distance 19
    .byte $80, $12
    ; literal count 111; subsequent asset bytes excluded
    .byte $6E
