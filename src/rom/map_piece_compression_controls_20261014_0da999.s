.setcpu "65816"
.segment "CODE"
.org $A999
map_control_0da999:
    .byte $E1 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
