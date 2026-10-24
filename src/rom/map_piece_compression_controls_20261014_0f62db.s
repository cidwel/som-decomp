.setcpu "65816"
.segment "CODE"
.org $62DB
map_control_0f62db:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
