.setcpu "65816"
.segment "CODE"
.org $6F82
map_control_0f6f82:
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
