.setcpu "65816"
.segment "CODE"
.org $9FF4
map_control_0f9ff4:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
