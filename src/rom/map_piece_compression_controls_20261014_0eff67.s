.setcpu "65816"
.segment "CODE"
.org $FF67
map_control_0eff67:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
