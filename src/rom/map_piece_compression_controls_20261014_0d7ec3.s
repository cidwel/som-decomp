.setcpu "65816"
.segment "CODE"
.org $7EC3
map_control_0d7ec3:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
