.setcpu "65816"
.segment "CODE"
.org $3A24
map_control_0d3a24:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
