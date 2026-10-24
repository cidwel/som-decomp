.setcpu "65816"
.segment "CODE"
.org $7094
map_control_0f7094:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
