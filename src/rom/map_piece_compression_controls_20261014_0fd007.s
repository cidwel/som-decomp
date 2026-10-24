.setcpu "65816"
.segment "CODE"
.org $D007
map_control_0fd007:
    .byte $CC ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
