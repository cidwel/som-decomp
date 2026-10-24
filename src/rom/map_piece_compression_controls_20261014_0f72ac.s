.setcpu "65816"
.segment "CODE"
.org $72AC
map_control_0f72ac:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $CA ; same-value copy count/distance
