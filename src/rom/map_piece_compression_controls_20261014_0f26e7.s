.setcpu "65816"
.segment "CODE"
.org $26E7
map_control_0f26e7:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
