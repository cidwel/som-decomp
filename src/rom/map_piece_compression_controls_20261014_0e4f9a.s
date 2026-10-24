.setcpu "65816"
.segment "CODE"
.org $4F9A
map_control_0e4f9a:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
