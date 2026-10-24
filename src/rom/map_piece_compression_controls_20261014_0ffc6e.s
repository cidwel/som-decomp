.setcpu "65816"
.segment "CODE"
.org $FC6E
map_control_0ffc6e:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
