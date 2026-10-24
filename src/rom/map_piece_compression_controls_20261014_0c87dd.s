.setcpu "65816"
.segment "CODE"
.org $87DD
map_control_0c87dd:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
