.setcpu "65816"
.segment "CODE"
.org $A45A
map_control_0fa45a:
    .byte $E1 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
