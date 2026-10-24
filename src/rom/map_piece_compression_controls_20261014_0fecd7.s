.setcpu "65816"
.segment "CODE"
.org $ECD7
map_control_0fecd7:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
