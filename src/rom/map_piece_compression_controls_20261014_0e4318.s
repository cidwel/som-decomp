.setcpu "65816"
.segment "CODE"
.org $4318
map_control_0e4318:
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
