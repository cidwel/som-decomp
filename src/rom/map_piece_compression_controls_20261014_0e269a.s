.setcpu "65816"
.segment "CODE"
.org $269A
map_control_0e269a:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
