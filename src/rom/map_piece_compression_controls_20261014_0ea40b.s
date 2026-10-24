.setcpu "65816"
.segment "CODE"
.org $A40B
map_control_0ea40b:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
