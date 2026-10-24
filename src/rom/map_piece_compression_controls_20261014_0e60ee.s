.setcpu "65816"
.segment "CODE"
.org $60EE
map_control_0e60ee:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
