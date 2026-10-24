.setcpu "65816"
.segment "CODE"
.org $3679
map_control_0c3679:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
