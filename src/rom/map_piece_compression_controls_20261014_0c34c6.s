.setcpu "65816"
.segment "CODE"
.org $34C6
map_control_0c34c6:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
