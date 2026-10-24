.setcpu "65816"
.segment "CODE"
.org $9134
map_control_0e9134:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
