.setcpu "65816"
.segment "CODE"
.org $3280
map_control_0f3280:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
