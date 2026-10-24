.setcpu "65816"
.segment "CODE"
.org $22EA
map_control_0f22ea:
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
