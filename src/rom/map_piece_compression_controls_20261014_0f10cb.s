.setcpu "65816"
.segment "CODE"
.org $10CB
map_control_0f10cb:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
