.setcpu "65816"
.segment "CODE"
.org $29A1
map_control_0f29a1:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
