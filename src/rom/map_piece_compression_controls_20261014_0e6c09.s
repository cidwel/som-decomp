.setcpu "65816"
.segment "CODE"
.org $6C09
map_control_0e6c09:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
