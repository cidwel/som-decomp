.setcpu "65816"
.segment "CODE"
.org $4AD1
map_control_0d4ad1:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
