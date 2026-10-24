.setcpu "65816"
.segment "CODE"
.org $DE04
map_control_0fde04:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
