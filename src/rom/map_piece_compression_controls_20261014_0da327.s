.setcpu "65816"
.segment "CODE"
.org $A327
map_control_0da327:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
