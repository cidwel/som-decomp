.setcpu "65816"
.segment "CODE"
.org $FF4A
map_control_0dff4a:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
