.setcpu "65816"
.segment "CODE"
.org $AD30
map_control_0ead30:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
