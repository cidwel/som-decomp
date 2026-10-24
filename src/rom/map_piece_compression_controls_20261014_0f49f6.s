.setcpu "65816"
.segment "CODE"
.org $49F6
map_control_0f49f6:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
