.setcpu "65816"
.segment "CODE"
.org $F636
map_control_0ef636:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
