.setcpu "65816"
.segment "CODE"
.org $779A
map_control_0d779a:
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
