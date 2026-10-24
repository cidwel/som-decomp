.setcpu "65816"
.segment "CODE"
.org $BF4B
map_control_0fbf4b:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
