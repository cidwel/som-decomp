.setcpu "65816"
.segment "CODE"
.org $F9DB
map_control_0df9db:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
