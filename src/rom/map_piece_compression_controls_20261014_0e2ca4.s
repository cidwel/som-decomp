.setcpu "65816"
.segment "CODE"
.org $2CA4
map_control_0e2ca4:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
