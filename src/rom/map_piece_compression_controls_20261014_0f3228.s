.setcpu "65816"
.segment "CODE"
.org $3228
map_control_0f3228:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
