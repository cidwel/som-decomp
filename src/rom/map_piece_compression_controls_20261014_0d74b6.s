.setcpu "65816"
.segment "CODE"
.org $74B6
map_control_0d74b6:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
