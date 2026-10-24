.setcpu "65816"
.segment "CODE"
.org $8A51
map_control_0c8a51:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
