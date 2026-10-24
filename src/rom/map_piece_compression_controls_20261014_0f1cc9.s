.setcpu "65816"
.segment "CODE"
.org $1CC9
map_control_0f1cc9:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
