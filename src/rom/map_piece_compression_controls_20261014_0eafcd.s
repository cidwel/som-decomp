.setcpu "65816"
.segment "CODE"
.org $AFCD
map_control_0eafcd:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
