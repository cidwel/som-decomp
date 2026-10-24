.setcpu "65816"
.segment "CODE"
.org $B75E
map_control_0db75e:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
