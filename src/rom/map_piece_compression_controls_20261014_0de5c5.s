.setcpu "65816"
.segment "CODE"
.org $E5C5
map_control_0de5c5:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
