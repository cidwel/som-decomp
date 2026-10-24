.setcpu "65816"
.segment "CODE"
.org $4280
map_control_0c4280:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
