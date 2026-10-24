.setcpu "65816"
.segment "CODE"
.org $77E4
map_control_0d77e4:
    .byte $E0 ; previous-row copy escape
    .byte $40 ; row-distance/count
