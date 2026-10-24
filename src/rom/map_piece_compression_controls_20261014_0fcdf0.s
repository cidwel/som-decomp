.setcpu "65816"
.segment "CODE"
.org $CDF0
map_control_0fcdf0:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
