.setcpu "65816"
.segment "CODE"
.org $A4F5
map_control_0fa4f5:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
