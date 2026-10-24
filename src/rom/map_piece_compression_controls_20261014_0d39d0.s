.setcpu "65816"
.segment "CODE"
.org $39D0
map_control_0d39d0:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
