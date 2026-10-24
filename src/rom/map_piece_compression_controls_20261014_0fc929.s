.setcpu "65816"
.segment "CODE"
.org $C929
map_control_0fc929:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
