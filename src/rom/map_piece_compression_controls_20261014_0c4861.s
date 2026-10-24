.setcpu "65816"
.segment "CODE"
.org $4861
map_control_0c4861:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
