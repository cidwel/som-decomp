.setcpu "65816"
.segment "CODE"
.org $FD0D
map_control_0efd0d:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
