.setcpu "65816"
.segment "CODE"
.org $2D49
map_control_0f2d49:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
