.setcpu "65816"
.segment "CODE"
.org $EA6C
map_control_0eea6c:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
