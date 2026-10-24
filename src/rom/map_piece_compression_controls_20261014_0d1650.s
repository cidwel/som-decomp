.setcpu "65816"
.segment "CODE"
.org $1650
map_control_0d1650:
    .byte $CE ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count
