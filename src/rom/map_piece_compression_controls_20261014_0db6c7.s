.setcpu "65816"
.segment "CODE"
.org $B6C7
map_control_0db6c7:
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
