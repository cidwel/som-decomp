.setcpu "65816"
.segment "CODE"
.org $8C4A
map_control_0d8c4a:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
