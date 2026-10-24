.setcpu "65816"
.segment "CODE"
.org $BF0A
map_control_0fbf0a:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
