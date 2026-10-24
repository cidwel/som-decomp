.setcpu "65816"
.segment "CODE"
.org $75C0
map_control_0f75c0:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
