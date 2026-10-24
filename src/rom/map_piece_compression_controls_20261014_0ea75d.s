.setcpu "65816"
.segment "CODE"
.org $A75D
map_control_0ea75d:
    .byte $C4 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
