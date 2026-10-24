.setcpu "65816"
.segment "CODE"
.org $1B6B
map_control_0e1b6b:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
