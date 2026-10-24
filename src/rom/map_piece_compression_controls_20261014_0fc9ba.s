.setcpu "65816"
.segment "CODE"
.org $C9BA
map_control_0fc9ba:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
