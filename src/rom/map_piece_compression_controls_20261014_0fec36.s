.setcpu "65816"
.segment "CODE"
.org $EC36
map_control_0fec36:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
