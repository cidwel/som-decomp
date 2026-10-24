.setcpu "65816"
.segment "CODE"
.org $5DDF
map_control_0f5ddf:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A7 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count
