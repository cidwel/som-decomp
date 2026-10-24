.setcpu "65816"
.segment "CODE"
.org $C3EA
map_control_0ec3ea:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
