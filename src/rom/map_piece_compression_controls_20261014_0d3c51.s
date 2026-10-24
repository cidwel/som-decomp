.setcpu "65816"
.segment "CODE"
.org $3C51
map_control_0d3c51:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
