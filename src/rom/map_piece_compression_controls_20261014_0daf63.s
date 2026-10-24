.setcpu "65816"
.segment "CODE"
.org $AF63
map_control_0daf63:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
