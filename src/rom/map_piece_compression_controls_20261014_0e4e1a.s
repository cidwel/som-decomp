.setcpu "65816"
.segment "CODE"
.org $4E1A
map_control_0e4e1a:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
