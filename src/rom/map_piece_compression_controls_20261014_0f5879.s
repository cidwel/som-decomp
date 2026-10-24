.setcpu "65816"
.segment "CODE"
.org $5879
map_control_0f5879:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
