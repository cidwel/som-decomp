.setcpu "65816"
.segment "CODE"
.org $C9E8
map_control_0ec9e8:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
