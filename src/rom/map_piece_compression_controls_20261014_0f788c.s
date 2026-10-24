.setcpu "65816"
.segment "CODE"
.org $788C
map_control_0f788c:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
