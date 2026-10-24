.setcpu "65816"
.segment "CODE"
.org $DCB7
map_control_0edcb7:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
