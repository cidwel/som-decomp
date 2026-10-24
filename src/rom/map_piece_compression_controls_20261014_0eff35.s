.setcpu "65816"
.segment "CODE"
.org $FF35
map_control_0eff35:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
