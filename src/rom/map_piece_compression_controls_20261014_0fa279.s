.setcpu "65816"
.segment "CODE"
.org $A279
map_control_0fa279:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
