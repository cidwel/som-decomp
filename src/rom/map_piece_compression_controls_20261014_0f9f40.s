.setcpu "65816"
.segment "CODE"
.org $9F40
map_control_0f9f40:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
