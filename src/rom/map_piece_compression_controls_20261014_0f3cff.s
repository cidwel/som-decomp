.setcpu "65816"
.segment "CODE"
.org $3CFF
map_control_0f3cff:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
