.setcpu "65816"
.segment "CODE"
.org $D7D7
map_control_0dd7d7:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $DD ; same-value copy count/distance
