.setcpu "65816"
.segment "CODE"
.org $4684
map_control_0f4684:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C3 ; same-value copy count/distance
