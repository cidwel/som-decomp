.setcpu "65816"
.segment "CODE"
.org $A93A
map_control_0da93a:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
