.setcpu "65816"
.segment "CODE"
.org $03DD
map_control_0f03dd:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
