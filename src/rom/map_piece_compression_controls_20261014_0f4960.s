.setcpu "65816"
.segment "CODE"
.org $4960
map_control_0f4960:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
