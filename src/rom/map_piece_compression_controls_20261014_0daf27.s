.setcpu "65816"
.segment "CODE"
.org $AF27
map_control_0daf27:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
