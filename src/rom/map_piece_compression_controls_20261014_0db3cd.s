.setcpu "65816"
.segment "CODE"
.org $B3CD
map_control_0db3cd:
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
