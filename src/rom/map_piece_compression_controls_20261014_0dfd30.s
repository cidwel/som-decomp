.setcpu "65816"
.segment "CODE"
.org $FD30
map_control_0dfd30:
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
