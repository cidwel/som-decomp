.setcpu "65816"
.segment "CODE"
.org $928D
map_control_0e928d:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
