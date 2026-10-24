.setcpu "65816"
.segment "CODE"
.org $41C3
map_control_0f41c3:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
