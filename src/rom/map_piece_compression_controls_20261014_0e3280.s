.setcpu "65816"
.segment "CODE"
.org $3280
map_control_0e3280:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
