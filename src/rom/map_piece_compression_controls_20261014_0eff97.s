.setcpu "65816"
.segment "CODE"
.org $FF97
map_control_0eff97:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
