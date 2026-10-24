.setcpu "65816"
.segment "CODE"
.org $F7E9
map_control_0df7e9:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
