.setcpu "65816"
.segment "CODE"
.org $7B0A
map_control_0f7b0a:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
