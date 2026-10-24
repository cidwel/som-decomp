.setcpu "65816"
.segment "CODE"
.org $638B
map_control_0c638b:
    .byte $E8 ; backreference distance high bits
    .byte $43 ; distance low bit/count
