.setcpu "65816"
.segment "CODE"
.org $54CD
map_control_0f54cd:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
