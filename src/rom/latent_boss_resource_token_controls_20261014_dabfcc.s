; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BFCC
boss_lz_controls_dabfcc:
    ; backreference count 3, distance 25
    .byte $80, $18
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
