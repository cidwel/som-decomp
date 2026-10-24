.setcpu "65816"
.segment "CODE"
.org $9005
map_control_0f9005:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
