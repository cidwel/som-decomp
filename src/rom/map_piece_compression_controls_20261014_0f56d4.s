.setcpu "65816"
.segment "CODE"
.org $56D4
map_control_0f56d4:
    .byte $C7 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
