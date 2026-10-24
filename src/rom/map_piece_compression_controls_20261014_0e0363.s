.setcpu "65816"
.segment "CODE"
.org $0363
map_control_0e0363:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
