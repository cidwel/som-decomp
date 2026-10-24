.setcpu "65816"
.segment "CODE"
.org $B64E
map_control_0db64e:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
