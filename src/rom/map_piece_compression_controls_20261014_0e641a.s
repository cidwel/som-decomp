.setcpu "65816"
.segment "CODE"
.org $641A
map_control_0e641a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
