; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA49
boss_lz_controls_dbba49:
    ; backreference count 3, distance 51
    .byte $80, $32
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
