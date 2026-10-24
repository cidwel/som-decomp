.setcpu "65816"
.segment "CODE"
.org $9BDF
map_control_0e9bdf:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
