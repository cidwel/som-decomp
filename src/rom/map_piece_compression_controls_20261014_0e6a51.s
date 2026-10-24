.setcpu "65816"
.segment "CODE"
.org $6A51
map_control_0e6a51:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
