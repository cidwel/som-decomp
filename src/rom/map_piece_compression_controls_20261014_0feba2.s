.setcpu "65816"
.segment "CODE"
.org $EBA2
map_control_0feba2:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
