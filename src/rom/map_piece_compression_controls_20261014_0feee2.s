.setcpu "65816"
.segment "CODE"
.org $EEE2
map_control_0feee2:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
