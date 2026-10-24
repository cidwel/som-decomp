.setcpu "65816"
.segment "CODE"
.org $4DED
map_control_0f4ded:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
