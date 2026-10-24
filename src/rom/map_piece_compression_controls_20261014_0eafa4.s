.setcpu "65816"
.segment "CODE"
.org $AFA4
map_control_0eafa4:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
