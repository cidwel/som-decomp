.setcpu "65816"
.segment "CODE"
.org $432A
map_control_0f432a:
    .byte $C4 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
