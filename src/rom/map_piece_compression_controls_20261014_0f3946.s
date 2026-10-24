.setcpu "65816"
.segment "CODE"
.org $3946
map_control_0f3946:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
