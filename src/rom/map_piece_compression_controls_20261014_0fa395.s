.setcpu "65816"
.segment "CODE"
.org $A395
map_control_0fa395:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
