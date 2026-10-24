.setcpu "65816"
.segment "CODE"
.org $B7FC
map_control_0db7fc:
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
