.setcpu "65816"
.segment "CODE"
.org $17E8
map_control_0f17e8:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
