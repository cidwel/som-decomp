.setcpu "65816"
.segment "CODE"
.org $C1F3
map_control_0dc1f3:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
