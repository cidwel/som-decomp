.setcpu "65816"
.segment "CODE"
.org $3F21
map_control_0f3f21:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
