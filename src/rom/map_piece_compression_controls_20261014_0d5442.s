.setcpu "65816"
.segment "CODE"
.org $5442
map_control_0d5442:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
