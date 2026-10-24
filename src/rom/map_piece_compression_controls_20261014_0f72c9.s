.setcpu "65816"
.segment "CODE"
.org $72C9
map_control_0f72c9:
    .byte $E6 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
