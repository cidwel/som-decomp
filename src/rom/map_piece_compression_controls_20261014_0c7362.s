.setcpu "65816"
.segment "CODE"
.org $7362
map_control_0c7362:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C3 ; same-value copy count/distance
