.setcpu "65816"
.segment "CODE"
.org $6619
map_control_0f6619:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
