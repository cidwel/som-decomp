; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9CFD
boss_lz_controls_db9cfd:
    ; backreference count 3, distance 329
    .byte $81, $48
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
