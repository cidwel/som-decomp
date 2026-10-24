.setcpu "65816"
.segment "CODE"
.org $F631
map_control_0df631:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
