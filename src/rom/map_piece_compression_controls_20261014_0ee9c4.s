.setcpu "65816"
.segment "CODE"
.org $E9C4
map_control_0ee9c4:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
