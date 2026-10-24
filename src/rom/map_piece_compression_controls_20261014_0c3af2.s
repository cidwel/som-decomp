.setcpu "65816"
.segment "CODE"
.org $3AF2
map_control_0c3af2:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
