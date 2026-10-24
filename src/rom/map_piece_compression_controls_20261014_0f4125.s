.setcpu "65816"
.segment "CODE"
.org $4125
map_control_0f4125:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
