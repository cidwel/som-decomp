.setcpu "65816"
.segment "CODE"
.org $2236
map_control_0d2236:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C6 ; same-value copy count/distance
