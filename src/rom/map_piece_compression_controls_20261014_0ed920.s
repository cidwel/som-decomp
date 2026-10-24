.setcpu "65816"
.segment "CODE"
.org $D920
map_control_0ed920:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
