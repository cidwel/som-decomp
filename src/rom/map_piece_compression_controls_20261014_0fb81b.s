.setcpu "65816"
.segment "CODE"
.org $B81B
map_control_0fb81b:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
