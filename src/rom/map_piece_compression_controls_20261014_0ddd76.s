.setcpu "65816"
.segment "CODE"
.org $DD76
map_control_0ddd76:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
