.setcpu "65816"
.segment "CODE"
.org $65F2
map_control_0c65f2:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
