.setcpu "65816"
.segment "CODE"
.org $7BB7
map_control_0e7bb7:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C6 ; same-value copy count/distance
