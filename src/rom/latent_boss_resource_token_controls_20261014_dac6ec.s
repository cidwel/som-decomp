; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C6EC
boss_lz_controls_dac6ec:
    ; backreference count 3, distance 107
    .byte $80, $6A
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
