.setcpu "65816"
.segment "CODE"
.org $BCA6
map_control_0ebca6:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
