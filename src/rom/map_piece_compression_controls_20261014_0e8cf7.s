.setcpu "65816"
.segment "CODE"
.org $8CF7
map_control_0e8cf7:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
