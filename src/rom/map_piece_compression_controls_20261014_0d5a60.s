.setcpu "65816"
.segment "CODE"
.org $5A60
map_control_0d5a60:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
