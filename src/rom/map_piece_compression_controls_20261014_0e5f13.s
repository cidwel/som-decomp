.setcpu "65816"
.segment "CODE"
.org $5F13
map_control_0e5f13:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
