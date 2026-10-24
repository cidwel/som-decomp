.setcpu "65816"
.segment "CODE"
.org $E80A
map_control_0de80a:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
