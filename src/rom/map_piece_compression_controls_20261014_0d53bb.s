.setcpu "65816"
.segment "CODE"
.org $53BB
map_control_0d53bb:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C5 ; same-value copy count/distance
