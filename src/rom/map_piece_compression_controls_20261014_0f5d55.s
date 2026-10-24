.setcpu "65816"
.segment "CODE"
.org $5D55
map_control_0f5d55:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
