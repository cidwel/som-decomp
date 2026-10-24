.setcpu "65816"
.segment "CODE"
.org $03FE
map_control_0e03fe:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
