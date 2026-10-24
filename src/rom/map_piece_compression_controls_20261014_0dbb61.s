.setcpu "65816"
.segment "CODE"
.org $BB61
map_control_0dbb61:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
