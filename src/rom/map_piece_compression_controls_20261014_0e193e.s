.setcpu "65816"
.segment "CODE"
.org $193E
map_control_0e193e:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
