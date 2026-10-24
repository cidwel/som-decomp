.setcpu "65816"
.segment "CODE"
.org $1C51
map_control_0d1c51:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C1 ; same-value copy count/distance
