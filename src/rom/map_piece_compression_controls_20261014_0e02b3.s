.setcpu "65816"
.segment "CODE"
.org $02B3
map_control_0e02b3:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
