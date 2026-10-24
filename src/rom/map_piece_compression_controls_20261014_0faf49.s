.setcpu "65816"
.segment "CODE"
.org $AF49
map_control_0faf49:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
