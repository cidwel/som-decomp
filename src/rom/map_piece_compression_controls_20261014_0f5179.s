.setcpu "65816"
.segment "CODE"
.org $5179
map_control_0f5179:
    .byte $E3 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
