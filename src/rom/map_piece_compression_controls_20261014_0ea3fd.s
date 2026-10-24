.setcpu "65816"
.segment "CODE"
.org $A3FD
map_control_0ea3fd:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
