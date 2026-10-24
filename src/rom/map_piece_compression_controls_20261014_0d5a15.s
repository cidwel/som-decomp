.setcpu "65816"
.segment "CODE"
.org $5A15
map_control_0d5a15:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C1 ; same-value copy count/distance
