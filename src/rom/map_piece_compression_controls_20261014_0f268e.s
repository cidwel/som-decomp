.setcpu "65816"
.segment "CODE"
.org $268E
map_control_0f268e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C1 ; same-value copy count/distance
