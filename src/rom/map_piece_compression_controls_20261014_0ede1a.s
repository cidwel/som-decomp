.setcpu "65816"
.segment "CODE"
.org $DE1A
map_control_0ede1a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
