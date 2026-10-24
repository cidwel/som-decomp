.setcpu "65816"
.segment "CODE"
.org $14EA
map_control_0d14ea:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
