.setcpu "65816"
.segment "CODE"
.org $4E33
map_control_0f4e33:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
