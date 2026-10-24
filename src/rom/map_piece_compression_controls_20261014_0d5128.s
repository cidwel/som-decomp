.setcpu "65816"
.segment "CODE"
.org $5128
map_control_0d5128:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
