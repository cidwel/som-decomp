.setcpu "65816"
.segment "CODE"
.org $FD14
map_control_0dfd14:
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
