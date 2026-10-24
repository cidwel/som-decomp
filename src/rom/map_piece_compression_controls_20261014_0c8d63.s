.setcpu "65816"
.segment "CODE"
.org $8D63
map_control_0c8d63:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
