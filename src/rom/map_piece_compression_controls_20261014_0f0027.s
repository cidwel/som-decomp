.setcpu "65816"
.segment "CODE"
.org $0027
map_control_0f0027:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
