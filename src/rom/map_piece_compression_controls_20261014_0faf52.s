.setcpu "65816"
.segment "CODE"
.org $AF52
map_control_0faf52:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
