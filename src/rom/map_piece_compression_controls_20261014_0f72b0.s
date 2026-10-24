.setcpu "65816"
.segment "CODE"
.org $72B0
map_control_0f72b0:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
