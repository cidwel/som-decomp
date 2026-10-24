.setcpu "65816"
.segment "CODE"
.org $7E97
map_control_0d7e97:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
