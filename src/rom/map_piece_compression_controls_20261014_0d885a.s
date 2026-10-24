.setcpu "65816"
.segment "CODE"
.org $885A
map_control_0d885a:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
