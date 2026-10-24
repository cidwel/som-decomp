; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF89
boss_lz_controls_dacf89:
    ; backreference count 3, distance 114
    .byte $80, $71
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
