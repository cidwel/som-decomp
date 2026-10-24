.setcpu "65816"
.segment "CODE"
.org $1665
map_control_0f1665:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
