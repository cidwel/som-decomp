.setcpu "65816"
.segment "CODE"
.org $BF60
map_control_0dbf60:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
