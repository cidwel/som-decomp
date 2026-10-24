.setcpu "65816"
.segment "CODE"
.org $AD47
map_control_0fad47:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
