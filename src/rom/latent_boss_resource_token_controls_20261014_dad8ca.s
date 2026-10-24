; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D8CA
boss_lz_controls_dad8ca:
    ; backreference count 3, distance 43
    .byte $80, $2A
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
