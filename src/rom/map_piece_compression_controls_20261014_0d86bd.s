.setcpu "65816"
.segment "CODE"
.org $86BD
map_control_0d86bd:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
