.setcpu "65816"
.segment "CODE"
.org $34F1
map_control_0f34f1:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
