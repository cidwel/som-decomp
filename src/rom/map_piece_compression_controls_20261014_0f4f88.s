.setcpu "65816"
.segment "CODE"
.org $4F88
map_control_0f4f88:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
