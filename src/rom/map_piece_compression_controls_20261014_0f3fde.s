.setcpu "65816"
.segment "CODE"
.org $3FDE
map_control_0f3fde:
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
