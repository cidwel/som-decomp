.setcpu "65816"
.segment "CODE"
.org $2A97
map_control_0f2a97:
    .byte $CC ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
