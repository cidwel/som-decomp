.setcpu "65816"
.segment "CODE"
.org $D318
map_control_0fd318:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
