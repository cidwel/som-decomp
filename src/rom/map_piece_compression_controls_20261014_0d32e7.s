.setcpu "65816"
.segment "CODE"
.org $32E7
map_control_0d32e7:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
