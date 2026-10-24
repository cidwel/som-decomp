.setcpu "65816"
.segment "CODE"
.org $774F
map_control_0d774f:
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
