.setcpu "65816"
.segment "CODE"
.org $D084
map_control_0fd084:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
