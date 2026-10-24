.setcpu "65816"
.segment "CODE"
.org $1264
map_control_0d1264:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
