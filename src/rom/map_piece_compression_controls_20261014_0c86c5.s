.setcpu "65816"
.segment "CODE"
.org $86C5
map_control_0c86c5:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
