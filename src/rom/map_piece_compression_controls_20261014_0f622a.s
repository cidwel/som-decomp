.setcpu "65816"
.segment "CODE"
.org $622A
map_control_0f622a:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
