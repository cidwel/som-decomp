.setcpu "65816"
.segment "CODE"
.org $8010
map_control_0d8010:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
