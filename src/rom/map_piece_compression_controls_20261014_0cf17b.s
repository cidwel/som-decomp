.setcpu "65816"
.segment "CODE"
.org $F17B
map_control_0cf17b:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C2 ; same-value copy count/distance
