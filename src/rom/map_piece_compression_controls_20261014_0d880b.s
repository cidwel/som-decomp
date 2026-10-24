.setcpu "65816"
.segment "CODE"
.org $880B
map_control_0d880b:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
