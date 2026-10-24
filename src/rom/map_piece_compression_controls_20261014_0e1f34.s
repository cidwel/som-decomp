.setcpu "65816"
.segment "CODE"
.org $1F34
map_control_0e1f34:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
