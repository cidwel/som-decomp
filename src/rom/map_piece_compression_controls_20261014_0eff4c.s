.setcpu "65816"
.segment "CODE"
.org $FF4C
map_control_0eff4c:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
