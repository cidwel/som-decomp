.setcpu "65816"
.segment "CODE"
.org $A73A
map_control_0ea73a:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
