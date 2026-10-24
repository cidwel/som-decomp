.setcpu "65816"
.segment "CODE"
.org $38D2
map_control_0f38d2:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
