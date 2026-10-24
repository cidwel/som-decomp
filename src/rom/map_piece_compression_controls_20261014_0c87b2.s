.setcpu "65816"
.segment "CODE"
.org $87B2
map_control_0c87b2:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C2 ; same-value copy count/distance
