.setcpu "65816"
.segment "CODE"
.org $5D29
map_control_0f5d29:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
