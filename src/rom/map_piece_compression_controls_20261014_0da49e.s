.setcpu "65816"
.segment "CODE"
.org $A49E
map_control_0da49e:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
