.setcpu "65816"
.segment "CODE"
.org $8D69
map_control_0f8d69:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
