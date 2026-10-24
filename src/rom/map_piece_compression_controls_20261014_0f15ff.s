.setcpu "65816"
.segment "CODE"
.org $15FF
map_control_0f15ff:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
