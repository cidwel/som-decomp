.setcpu "65816"
.segment "CODE"
.org $82C5
map_control_0d82c5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
