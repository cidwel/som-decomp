.setcpu "65816"
.segment "CODE"
.org $02CD
map_control_0e02cd:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
