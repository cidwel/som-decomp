.setcpu "65816"
.segment "CODE"
.org $F795
map_control_0df795:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
