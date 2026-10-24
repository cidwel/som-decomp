.setcpu "65816"
.segment "CODE"
.org $46F2
map_control_0f46f2:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
