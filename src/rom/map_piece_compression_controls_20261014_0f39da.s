.setcpu "65816"
.segment "CODE"
.org $39DA
map_control_0f39da:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C4 ; same-value copy count/distance
