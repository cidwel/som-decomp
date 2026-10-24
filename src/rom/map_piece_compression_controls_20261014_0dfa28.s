.setcpu "65816"
.segment "CODE"
.org $FA28
map_control_0dfa28:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
