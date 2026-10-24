.setcpu "65816"
.segment "CODE"
.org $82E5
map_control_0e82e5:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
