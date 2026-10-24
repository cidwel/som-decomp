.setcpu "65816"
.segment "CODE"
.org $A1CB
map_control_0fa1cb:
    .byte $C7 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
