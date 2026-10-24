.setcpu "65816"
.segment "CODE"
.org $A401
map_control_0ea401:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
