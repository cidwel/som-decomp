.setcpu "65816"
.segment "CODE"
.org $2D51
map_control_0d2d51:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
