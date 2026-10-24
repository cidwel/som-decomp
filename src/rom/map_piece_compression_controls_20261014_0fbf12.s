.setcpu "65816"
.segment "CODE"
.org $BF12
map_control_0fbf12:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
