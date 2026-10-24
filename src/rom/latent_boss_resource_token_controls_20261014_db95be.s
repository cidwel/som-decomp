; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $95BE
boss_lz_controls_db95be:
    ; backreference count 3, distance 84
    .byte $80, $53
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
