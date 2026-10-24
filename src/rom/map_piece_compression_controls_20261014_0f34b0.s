.setcpu "65816"
.segment "CODE"
.org $34B0
map_control_0f34b0:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
