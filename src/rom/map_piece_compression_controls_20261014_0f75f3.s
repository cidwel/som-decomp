.setcpu "65816"
.segment "CODE"
.org $75F3
map_control_0f75f3:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
