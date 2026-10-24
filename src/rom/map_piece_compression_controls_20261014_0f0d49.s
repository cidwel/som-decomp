.setcpu "65816"
.segment "CODE"
.org $0D49
map_control_0f0d49:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
