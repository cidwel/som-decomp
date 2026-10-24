.setcpu "65816"
.segment "CODE"
.org $3F80
map_control_0e3f80:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
