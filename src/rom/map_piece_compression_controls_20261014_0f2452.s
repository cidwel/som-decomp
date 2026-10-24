.setcpu "65816"
.segment "CODE"
.org $2452
map_control_0f2452:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
