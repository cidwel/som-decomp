.setcpu "65816"
.segment "CODE"
.org $9F2A
map_control_0f9f2a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
