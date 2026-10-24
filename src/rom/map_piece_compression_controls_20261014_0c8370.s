.setcpu "65816"
.segment "CODE"
.org $8370
map_control_0c8370:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
