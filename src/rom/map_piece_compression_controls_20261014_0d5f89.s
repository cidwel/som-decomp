.setcpu "65816"
.segment "CODE"
.org $5F89
map_control_0d5f89:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
