.setcpu "65816"
.segment "CODE"
.org $CD04
map_control_0fcd04:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
