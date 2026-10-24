.setcpu "65816"
.segment "CODE"
.org $F6F9
map_control_0df6f9:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
