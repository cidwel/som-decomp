.setcpu "65816"
.segment "CODE"
.org $0BF2
map_control_0f0bf2:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $D3 ; same-value copy count/distance
