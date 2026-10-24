.setcpu "65816"
.segment "CODE"
.org $BD59
map_control_0ebd59:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
