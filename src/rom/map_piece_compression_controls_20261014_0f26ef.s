.setcpu "65816"
.segment "CODE"
.org $26EF
map_control_0f26ef:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
