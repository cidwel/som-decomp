.setcpu "65816"
.segment "CODE"
.org $337B
map_control_0e337b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
