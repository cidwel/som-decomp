.setcpu "65816"
.segment "CODE"
.org $78DD
map_control_0c78dd:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
