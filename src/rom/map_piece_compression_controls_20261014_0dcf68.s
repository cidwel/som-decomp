.setcpu "65816"
.segment "CODE"
.org $CF68
map_control_0dcf68:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
