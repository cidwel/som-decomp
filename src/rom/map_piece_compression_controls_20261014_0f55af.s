.setcpu "65816"
.segment "CODE"
.org $55AF
map_control_0f55af:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
