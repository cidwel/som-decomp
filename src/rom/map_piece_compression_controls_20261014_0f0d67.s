.setcpu "65816"
.segment "CODE"
.org $0D67
map_control_0f0d67:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
