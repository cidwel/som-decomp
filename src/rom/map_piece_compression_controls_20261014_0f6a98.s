.setcpu "65816"
.segment "CODE"
.org $6A98
map_control_0f6a98:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
