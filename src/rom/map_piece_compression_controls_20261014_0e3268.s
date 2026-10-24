.setcpu "65816"
.segment "CODE"
.org $3268
map_control_0e3268:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
