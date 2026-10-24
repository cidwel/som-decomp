.setcpu "65816"
.segment "CODE"
.org $3B4C
map_control_0f3b4c:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
