.setcpu "65816"
.segment "CODE"
.org $76E1
map_control_0d76e1:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
