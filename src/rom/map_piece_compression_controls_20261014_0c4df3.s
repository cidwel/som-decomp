.setcpu "65816"
.segment "CODE"
.org $4DF3
map_control_0c4df3:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
