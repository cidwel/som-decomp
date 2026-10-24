.setcpu "65816"
.segment "CODE"
.org $ACE4
map_control_0face4:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
