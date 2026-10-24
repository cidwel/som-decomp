.setcpu "65816"
.segment "CODE"
.org $DE32
map_control_0dde32:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
