.setcpu "65816"
.segment "CODE"
.org $02AA
map_control_0f02aa:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
