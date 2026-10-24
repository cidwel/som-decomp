; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $001A
boss_lz_controls_db001a:
    ; backreference count 5, distance 6
    .byte $A0, $05
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
