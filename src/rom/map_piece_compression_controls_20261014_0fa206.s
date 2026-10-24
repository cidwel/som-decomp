.setcpu "65816"
.segment "CODE"
.org $A206
map_control_0fa206:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $DA ; same-value copy count/distance
