.setcpu "65816"
.segment "CODE"
.org $B861
map_control_0fb861:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
