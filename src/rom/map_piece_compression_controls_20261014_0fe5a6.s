.setcpu "65816"
.segment "CODE"
.org $E5A6
map_control_0fe5a6:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
