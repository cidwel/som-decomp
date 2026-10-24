.setcpu "65816"
.segment "CODE"
.org $4A87
map_control_0c4a87:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
