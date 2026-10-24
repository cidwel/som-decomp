.setcpu "65816"
.segment "CODE"
.org $899C
map_control_0e899c:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
