.setcpu "65816"
.segment "CODE"
.org $A675
map_control_0da675:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
