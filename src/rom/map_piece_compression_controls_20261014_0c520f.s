.setcpu "65816"
.segment "CODE"
.org $520F
map_control_0c520f:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
