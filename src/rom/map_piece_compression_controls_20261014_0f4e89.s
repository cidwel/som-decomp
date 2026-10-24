.setcpu "65816"
.segment "CODE"
.org $4E89
map_control_0f4e89:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
