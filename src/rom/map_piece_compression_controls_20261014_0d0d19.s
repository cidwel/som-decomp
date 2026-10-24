.setcpu "65816"
.segment "CODE"
.org $0D19
map_control_0d0d19:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
