.setcpu "65816"
.segment "CODE"
.org $8FB4
map_control_0d8fb4:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
