.setcpu "65816"
.segment "CODE"
.org $9105
map_control_0e9105:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
