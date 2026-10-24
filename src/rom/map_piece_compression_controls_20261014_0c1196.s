.setcpu "65816"
.segment "CODE"
.org $1196
map_control_0c1196:
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
