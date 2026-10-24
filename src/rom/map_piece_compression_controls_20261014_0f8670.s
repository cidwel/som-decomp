.setcpu "65816"
.segment "CODE"
.org $8670
map_control_0f8670:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
