.setcpu "65816"
.segment "CODE"
.org $8D0B
map_control_0f8d0b:
    .byte $E0 ; previous-row copy escape
    .byte $BA ; row-distance/count
    .byte $C1 ; same-value copy count/distance
