.setcpu "65816"
.segment "CODE"
.org $0D50
map_control_0f0d50:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
