.setcpu "65816"
.segment "CODE"
.org $3F7D
map_control_0c3f7d:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
