.setcpu "65816"
.segment "CODE"
.org $BFE7
map_control_0fbfe7:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
