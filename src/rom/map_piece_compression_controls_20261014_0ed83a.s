.setcpu "65816"
.segment "CODE"
.org $D83A
map_control_0ed83a:
    .byte $E6 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
