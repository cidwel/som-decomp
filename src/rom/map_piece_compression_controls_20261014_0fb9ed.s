.setcpu "65816"
.segment "CODE"
.org $B9ED
map_control_0fb9ed:
    .byte $CC ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
