.setcpu "65816"
.segment "CODE"
.org $3501
map_control_0e3501:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
