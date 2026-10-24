.setcpu "65816"
.segment "CODE"
.org $3DF3
map_control_0d3df3:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
