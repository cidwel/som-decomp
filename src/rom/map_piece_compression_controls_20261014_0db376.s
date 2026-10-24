.setcpu "65816"
.segment "CODE"
.org $B376
map_control_0db376:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
