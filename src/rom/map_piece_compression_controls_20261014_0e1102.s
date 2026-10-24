.setcpu "65816"
.segment "CODE"
.org $1102
map_control_0e1102:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $32 ; distance low bit/count
