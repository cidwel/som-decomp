.setcpu "65816"
.segment "CODE"
.org $811E
map_control_0d811e:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
