.setcpu "65816"
.segment "CODE"
.org $E9CD
map_control_0fe9cd:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
