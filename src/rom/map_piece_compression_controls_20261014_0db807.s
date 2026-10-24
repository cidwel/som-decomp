.setcpu "65816"
.segment "CODE"
.org $B807
map_control_0db807:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
