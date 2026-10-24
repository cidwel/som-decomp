; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB46
boss_lz_controls_dbcb46:
    ; backreference count 3, distance 101
    .byte $80, $64
    ; backreference count 3, distance 59
    .byte $80, $3A
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
