.setcpu "65816"
.segment "CODE"
.org $BDA0
map_control_0fbda0:
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count
