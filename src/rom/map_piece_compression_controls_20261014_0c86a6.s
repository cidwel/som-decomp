.setcpu "65816"
.segment "CODE"
.org $86A6
map_control_0c86a6:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
