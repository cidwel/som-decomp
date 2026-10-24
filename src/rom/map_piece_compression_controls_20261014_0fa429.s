.setcpu "65816"
.segment "CODE"
.org $A429
map_control_0fa429:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
