.setcpu "65816"
.segment "CODE"
.org $E796
map_control_0fe796:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
