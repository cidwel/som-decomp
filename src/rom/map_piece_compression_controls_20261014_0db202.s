.setcpu "65816"
.segment "CODE"
.org $B202
map_control_0db202:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
