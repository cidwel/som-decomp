.setcpu "65816"
.segment "CODE"
.org $8D98
map_control_0f8d98:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $D1 ; same-value copy count/distance
