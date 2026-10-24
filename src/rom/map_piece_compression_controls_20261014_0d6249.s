.setcpu "65816"
.segment "CODE"
.org $6249
map_control_0d6249:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C1 ; same-value copy count/distance
