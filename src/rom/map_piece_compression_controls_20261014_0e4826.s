.setcpu "65816"
.segment "CODE"
.org $4826
map_control_0e4826:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
