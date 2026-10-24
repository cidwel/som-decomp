.setcpu "65816"
.segment "CODE"
.org $02DF
map_control_0e02df:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
