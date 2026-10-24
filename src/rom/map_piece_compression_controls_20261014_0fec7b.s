.setcpu "65816"
.segment "CODE"
.org $EC7B
map_control_0fec7b:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
