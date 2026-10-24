.setcpu "65816"
.segment "CODE"
.org $7C75
map_control_0c7c75:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
