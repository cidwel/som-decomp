.setcpu "65816"
.segment "CODE"
.org $79DF
map_control_0f79df:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
