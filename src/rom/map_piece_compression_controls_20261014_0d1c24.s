.setcpu "65816"
.segment "CODE"
.org $1C24
map_control_0d1c24:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
