.setcpu "65816"
.segment "CODE"
.org $2862
map_control_0e2862:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
