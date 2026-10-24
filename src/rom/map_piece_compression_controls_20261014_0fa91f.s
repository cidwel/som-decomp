.setcpu "65816"
.segment "CODE"
.org $A91F
map_control_0fa91f:
    .byte $CB ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
