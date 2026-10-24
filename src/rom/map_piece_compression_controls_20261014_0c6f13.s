.setcpu "65816"
.segment "CODE"
.org $6F13
map_control_0c6f13:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
