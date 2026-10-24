.setcpu "65816"
.segment "CODE"
.org $1537
map_control_0d1537:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
