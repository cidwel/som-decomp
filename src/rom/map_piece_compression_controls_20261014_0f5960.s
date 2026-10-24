.setcpu "65816"
.segment "CODE"
.org $5960
map_control_0f5960:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
