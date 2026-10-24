.setcpu "65816"
.segment "CODE"
.org $E8F4
map_control_0de8f4:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
