.setcpu "65816"
.segment "CODE"
.org $83DA
map_control_0c83da:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
