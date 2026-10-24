.setcpu "65816"
.segment "CODE"
.org $98C9
map_control_0d98c9:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
