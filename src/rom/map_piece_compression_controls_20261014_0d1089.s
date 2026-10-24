.setcpu "65816"
.segment "CODE"
.org $1089
map_control_0d1089:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
