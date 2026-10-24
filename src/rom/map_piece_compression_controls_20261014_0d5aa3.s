.setcpu "65816"
.segment "CODE"
.org $5AA3
map_control_0d5aa3:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
