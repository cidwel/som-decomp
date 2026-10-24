; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $068B
boss_lz_controls_db068b:
    ; backreference count 5, distance 1337
    .byte $A5, $38
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
