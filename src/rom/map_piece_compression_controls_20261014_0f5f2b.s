.setcpu "65816"
.segment "CODE"
.org $5F2B
map_control_0f5f2b:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
