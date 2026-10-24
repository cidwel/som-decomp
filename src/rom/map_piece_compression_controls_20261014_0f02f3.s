.setcpu "65816"
.segment "CODE"
.org $02F3
map_control_0f02f3:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
