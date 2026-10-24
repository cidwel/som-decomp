.setcpu "65816"
.segment "CODE"
.org $A704
map_control_0fa704:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
