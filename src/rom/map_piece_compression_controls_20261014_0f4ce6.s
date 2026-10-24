.setcpu "65816"
.segment "CODE"
.org $4CE6
map_control_0f4ce6:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
