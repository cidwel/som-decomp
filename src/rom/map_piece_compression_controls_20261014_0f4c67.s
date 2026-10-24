.setcpu "65816"
.segment "CODE"
.org $4C67
map_control_0f4c67:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
