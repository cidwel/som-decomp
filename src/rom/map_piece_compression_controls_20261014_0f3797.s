.setcpu "65816"
.segment "CODE"
.org $3797
map_control_0f3797:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C1 ; same-value copy count/distance
