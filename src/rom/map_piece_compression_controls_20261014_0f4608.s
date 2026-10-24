.setcpu "65816"
.segment "CODE"
.org $4608
map_control_0f4608:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
