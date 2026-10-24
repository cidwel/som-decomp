.setcpu "65816"
.segment "CODE"
.org $3F36
map_control_0d3f36:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
