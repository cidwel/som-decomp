.setcpu "65816"
.segment "CODE"
.org $5509
map_control_0d5509:
    .byte $C9 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
