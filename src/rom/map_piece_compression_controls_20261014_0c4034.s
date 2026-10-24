.setcpu "65816"
.segment "CODE"
.org $4034
map_control_0c4034:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
