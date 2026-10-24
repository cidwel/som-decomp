; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C17C
boss_lz_controls_dac17c:
    ; backreference count 3, distance 19
    .byte $80, $12
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
