.setcpu "65816"
.segment "CODE"
.org $60A6
map_control_0f60a6:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
