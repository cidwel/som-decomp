.setcpu "65816"
.segment "CODE"
.org $CDF4
map_control_0fcdf4:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
