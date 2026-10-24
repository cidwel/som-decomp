.setcpu "65816"
.segment "CODE"
.org $825F
map_control_0d825f:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
