.setcpu "65816"
.segment "CODE"
.org $B7B5
map_control_0db7b5:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
