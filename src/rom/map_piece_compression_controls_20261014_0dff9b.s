.setcpu "65816"
.segment "CODE"
.org $FF9B
map_control_0dff9b:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
