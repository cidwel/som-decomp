.setcpu "65816"
.segment "CODE"
.org $A4FE
map_control_0fa4fe:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
