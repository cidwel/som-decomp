.setcpu "65816"
.segment "CODE"
.org $7402
map_control_0e7402:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
