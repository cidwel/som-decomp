.setcpu "65816"
.segment "CODE"
.org $1166
map_control_0d1166:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
