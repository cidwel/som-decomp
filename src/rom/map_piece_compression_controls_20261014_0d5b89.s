.setcpu "65816"
.segment "CODE"
.org $5B89
map_control_0d5b89:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
