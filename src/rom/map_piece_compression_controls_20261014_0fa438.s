.setcpu "65816"
.segment "CODE"
.org $A438
map_control_0fa438:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
