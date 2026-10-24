.setcpu "65816"
.segment "CODE"
.org $D7B7
map_control_0fd7b7:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
