.setcpu "65816"
.segment "CODE"
.org $C2B1
map_control_0fc2b1:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
