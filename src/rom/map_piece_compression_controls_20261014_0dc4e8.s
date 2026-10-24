.setcpu "65816"
.segment "CODE"
.org $C4E8
map_control_0dc4e8:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
