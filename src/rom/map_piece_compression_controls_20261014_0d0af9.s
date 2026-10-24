.setcpu "65816"
.segment "CODE"
.org $0AF9
map_control_0d0af9:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
