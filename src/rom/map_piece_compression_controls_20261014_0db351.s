.setcpu "65816"
.segment "CODE"
.org $B351
map_control_0db351:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
