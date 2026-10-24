.setcpu "65816"
.segment "CODE"
.org $0405
map_control_0f0405:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
