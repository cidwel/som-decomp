.setcpu "65816"
.segment "CODE"
.org $8F63
map_control_0e8f63:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
