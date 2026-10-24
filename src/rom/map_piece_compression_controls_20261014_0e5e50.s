.setcpu "65816"
.segment "CODE"
.org $5E50
map_control_0e5e50:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
