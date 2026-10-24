.setcpu "65816"
.segment "CODE"
.org $C9A1
map_control_0fc9a1:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
