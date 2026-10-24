.setcpu "65816"
.segment "CODE"
.org $7D83
map_control_0c7d83:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
