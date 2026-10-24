.setcpu "65816"
.segment "CODE"
.org $A087
map_control_0ea087:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
