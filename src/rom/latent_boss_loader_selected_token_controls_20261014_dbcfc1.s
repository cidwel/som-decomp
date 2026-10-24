; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CFC1
boss_lz_controls_dbcfc1:
    ; backreference count 3, distance 337
    .byte $81, $50
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
