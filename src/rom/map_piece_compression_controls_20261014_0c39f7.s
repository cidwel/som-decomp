.setcpu "65816"
.segment "CODE"
.org $39F7
map_control_0c39f7:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
