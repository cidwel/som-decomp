.setcpu "65816"
.segment "CODE"
.org $8E87
map_control_0e8e87:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
