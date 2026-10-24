.setcpu "65816"
.segment "CODE"
.org $A40F
map_control_0ea40f:
    .byte $DC ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
