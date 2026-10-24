.setcpu "65816"
.segment "CODE"
.org $F200
map_control_0ef200:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
