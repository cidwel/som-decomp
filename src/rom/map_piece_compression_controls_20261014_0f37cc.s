.setcpu "65816"
.segment "CODE"
.org $37CC
map_control_0f37cc:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
