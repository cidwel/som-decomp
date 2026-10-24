.setcpu "65816"
.segment "CODE"
.org $5330
map_control_0f5330:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
