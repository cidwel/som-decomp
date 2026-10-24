.setcpu "65816"
.segment "CODE"
.org $B524
map_control_0eb524:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
