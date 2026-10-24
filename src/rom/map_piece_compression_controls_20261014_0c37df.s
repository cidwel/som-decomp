.setcpu "65816"
.segment "CODE"
.org $37DF
map_control_0c37df:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
