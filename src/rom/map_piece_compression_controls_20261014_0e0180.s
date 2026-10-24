.setcpu "65816"
.segment "CODE"
.org $0180
map_control_0e0180:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
