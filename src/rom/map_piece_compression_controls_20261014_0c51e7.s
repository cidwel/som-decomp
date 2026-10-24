.setcpu "65816"
.segment "CODE"
.org $51E7
map_control_0c51e7:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
