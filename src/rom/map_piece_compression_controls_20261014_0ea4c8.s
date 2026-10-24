.setcpu "65816"
.segment "CODE"
.org $A4C8
map_control_0ea4c8:
    .byte $C5 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
