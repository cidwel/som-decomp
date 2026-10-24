.setcpu "65816"
.segment "CODE"
.org $4E55
map_control_0d4e55:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
