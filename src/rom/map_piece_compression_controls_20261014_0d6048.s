.setcpu "65816"
.segment "CODE"
.org $6048
map_control_0d6048:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
