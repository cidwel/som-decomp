.setcpu "65816"
.segment "CODE"
.org $DEE0
map_control_0edee0:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
