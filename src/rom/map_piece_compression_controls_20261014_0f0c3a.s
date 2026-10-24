.setcpu "65816"
.segment "CODE"
.org $0C3A
map_control_0f0c3a:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
