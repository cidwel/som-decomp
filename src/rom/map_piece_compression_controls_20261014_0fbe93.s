.setcpu "65816"
.segment "CODE"
.org $BE93
map_control_0fbe93:
    .byte $D6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
