.setcpu "65816"
.segment "CODE"
.org $C5EE
map_control_0dc5ee:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
