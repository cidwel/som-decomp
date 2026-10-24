.setcpu "65816"
.segment "CODE"
.org $A937
map_control_0ea937:
    .byte $C9 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
