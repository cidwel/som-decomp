.setcpu "65816"
.segment "CODE"
.org $49DD
map_control_0f49dd:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
