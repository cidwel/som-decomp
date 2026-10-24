.setcpu "65816"
.segment "CODE"
.org $E501
map_control_0fe501:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
