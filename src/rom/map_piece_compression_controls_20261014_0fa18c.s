.setcpu "65816"
.segment "CODE"
.org $A18C
map_control_0fa18c:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
