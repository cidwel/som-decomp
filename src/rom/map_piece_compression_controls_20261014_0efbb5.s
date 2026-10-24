.setcpu "65816"
.segment "CODE"
.org $FBB5
map_control_0efbb5:
    .byte $E1 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
