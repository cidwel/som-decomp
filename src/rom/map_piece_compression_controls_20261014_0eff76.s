.setcpu "65816"
.segment "CODE"
.org $FF76
map_control_0eff76:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
