.setcpu "65816"
.segment "CODE"
.org $AC30
map_control_0fac30:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
