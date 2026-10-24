.setcpu "65816"
.segment "CODE"
.org $A607
map_control_0fa607:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
