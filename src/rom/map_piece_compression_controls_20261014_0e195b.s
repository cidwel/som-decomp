.setcpu "65816"
.segment "CODE"
.org $195B
map_control_0e195b:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
