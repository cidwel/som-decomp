.setcpu "65816"
.segment "CODE"
.org $696E
map_control_0c696e:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
