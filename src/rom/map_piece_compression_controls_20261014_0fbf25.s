.setcpu "65816"
.segment "CODE"
.org $BF25
map_control_0fbf25:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
