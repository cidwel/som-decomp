.setcpu "65816"
.segment "CODE"
.org $3C7C
map_control_0e3c7c:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
