.setcpu "65816"
.segment "CODE"
.org $7B65
map_control_0d7b65:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
