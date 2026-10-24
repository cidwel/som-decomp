.setcpu "65816"
.segment "CODE"
.org $A637
map_control_0da637:
    .byte $E3 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
