.setcpu "65816"
.segment "CODE"
.org $0D35
map_control_0f0d35:
    .byte $D5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
