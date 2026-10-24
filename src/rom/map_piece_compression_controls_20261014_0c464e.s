.setcpu "65816"
.segment "CODE"
.org $464E
map_control_0c464e:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
