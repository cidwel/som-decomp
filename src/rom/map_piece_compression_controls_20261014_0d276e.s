.setcpu "65816"
.segment "CODE"
.org $276E
map_control_0d276e:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
