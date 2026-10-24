.setcpu "65816"
.segment "CODE"
.org $D6F5
map_control_0ed6f5:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
