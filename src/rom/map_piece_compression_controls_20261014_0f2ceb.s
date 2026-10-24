.setcpu "65816"
.segment "CODE"
.org $2CEB
map_control_0f2ceb:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
