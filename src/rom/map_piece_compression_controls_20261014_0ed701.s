.setcpu "65816"
.segment "CODE"
.org $D701
map_control_0ed701:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
