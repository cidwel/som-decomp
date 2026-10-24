.setcpu "65816"
.segment "CODE"
.org $4EF9
map_control_0f4ef9:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
