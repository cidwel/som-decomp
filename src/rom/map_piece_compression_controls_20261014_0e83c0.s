.setcpu "65816"
.segment "CODE"
.org $83C0
map_control_0e83c0:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
