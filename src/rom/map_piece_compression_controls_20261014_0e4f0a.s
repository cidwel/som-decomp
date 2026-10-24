.setcpu "65816"
.segment "CODE"
.org $4F0A
map_control_0e4f0a:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C2 ; same-value copy count/distance
