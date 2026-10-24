.setcpu "65816"
.segment "CODE"
.org $4CD0
map_control_0d4cd0:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
