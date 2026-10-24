.setcpu "65816"
.segment "CODE"
.org $AF9D
map_control_0daf9d:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
