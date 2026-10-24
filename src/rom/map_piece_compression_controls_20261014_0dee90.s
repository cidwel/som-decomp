.setcpu "65816"
.segment "CODE"
.org $EE90
map_control_0dee90:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
