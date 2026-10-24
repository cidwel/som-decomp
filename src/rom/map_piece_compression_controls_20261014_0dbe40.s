.setcpu "65816"
.segment "CODE"
.org $BE40
map_control_0dbe40:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
