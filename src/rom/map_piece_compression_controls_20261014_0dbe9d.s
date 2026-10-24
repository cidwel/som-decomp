.setcpu "65816"
.segment "CODE"
.org $BE9D
map_control_0dbe9d:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
