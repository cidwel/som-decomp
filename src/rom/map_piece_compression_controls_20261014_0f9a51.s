.setcpu "65816"
.segment "CODE"
.org $9A51
map_control_0f9a51:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
