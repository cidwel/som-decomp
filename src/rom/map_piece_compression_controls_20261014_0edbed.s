.setcpu "65816"
.segment "CODE"
.org $DBED
map_control_0edbed:
    .byte $D3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
