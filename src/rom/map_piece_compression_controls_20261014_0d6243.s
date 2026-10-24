.setcpu "65816"
.segment "CODE"
.org $6243
map_control_0d6243:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
