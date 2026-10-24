.setcpu "65816"
.segment "CODE"
.org $9A33
map_control_0f9a33:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
